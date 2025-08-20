#include <iostream>
using namespace std;

class Employee
{

	int employee_id, age;
	float salary;
	string name;

public:
	void setEmployee(int employee_id, string name, int age, float salary)
	{
		this->employee_id = employee_id;
		this->name = name;
		this->age = age;
		this->salary = salary;
	}

	int getEmployeeId()
	{
		return this->employee_id;
	}

	int getEmployeeAge()
	{
		return this->age;
	}

	float getEmployeeSalary()
	{
		return this->salary;
	}

	string getEmployeeName()
	{
		return this->name;
	}

	void display()
	{
		cout << "Employee id is: " << employee_id << endl
			 << "Employee name is: " << name << endl
			 << "Employee age is: " << age << endl
			 << "Employee salary is: " << salary << endl;
	}
};

class FullTimeEmployee : public Employee
{
	float bonus;

public:
	void setBonus(float bonus)
	{
		this->bonus = bonus;
	}

	float getBonus()
	{
		return bonus;
	}

	void display()
	{
		Employee::display();
		cout << "Employee bonus is: " << this->bonus << endl;
	}
};

class PartTimeEmployee : public Employee
{
	int hours_worked;

public:
	void setHoursWorked(int hours_worked)
	{
		this->hours_worked = hours_worked;
	}

	int getHoursWorked()
	{
		this->hours_worked = hours_worked;
	}

	void display()
	{
		Employee::display();
		cout << "Hours worked is: " << this->hours_worked << endl;
	}
};

int main()
{
	Employee *emp[100];
	int count = 0;
	int choice, size;
	int emp_id, emp_age, emp_hours_worked;
	float emp_salary, emp_bonus;
	string emp_name;

	do
	{
		cout << "-------------Employee Registration Menu-------------" << endl;
		cout << "1.Add Employee (Fulltime/Partime) Employee" << endl;
		cout << "2.Display All employee" << endl;
		cout << "3.Delete Employee" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter 1 for Full Time Employee " << endl;
			cout << "Enter 2 for Part Time Employee " << endl;
			cout << "Enter your choice: ";

			cin >> choice;

			if (choice == 1)
			{
				cout << "How many full time employees you want to store ?" << endl;
				cout << "Enter size: ";
				cin >> size;

				if (count + size > 100)
				{
					cout << "Not enough space to store " << size << " employees!" << endl;
				}

				else
				{
					for (int i = 0; i < size; i++)
					{
						cout << endl
							 << "-------Enter Employee " << i + 1 << " details-------" << endl;
						cout << "Enter Employee id: ";
						cin >> emp_id;
						cout << "Enter Employee name: ";
						cin.ignore();
						getline(cin, emp_name);
						cout << "Enter Employee age: ";
						cin >> emp_age;
						cout << "Enter Employee salary: ";
						cin >> emp_salary;
						cout << "Enter Employee bonus: ";
						cin >> emp_bonus;
						cout << endl;

						emp[count] = new FullTimeEmployee();
						emp[count]->setEmployee(emp_id, emp_name, emp_age, emp_salary);
						((FullTimeEmployee *)emp[count])->setBonus(emp_bonus);
						count++;
					}
				}
			}

			else if (choice == 2)
			{
				cout << "How many part time employees you want to store ?" << endl;
				cout << "Enter size: ";
				cin >> size;

				if (count + size > 100)
				{
					cout << "Not enough space to store " << size << " employees!" << endl;
				}
				else
				{
					for (int i = 0; i < size; i++)
					{
						cout << endl
							 << "-------Enter Employee " << i + 1 << " details-------" << endl;
						cout << "Enter Employee id: ";
						cin >> emp_id;
						cout << "Enter Employee name: ";
						cin.ignore();
						getline(cin, emp_name);
						cout << "Enter Employee age: ";
						cin >> emp_age;
						cout << "Enter Employee salary: ";
						cin >> emp_salary;
						cout << "Enter Employee Worked Hours: ";
						cin >> emp_bonus;
						cout << endl;

						emp[count] = new FullTimeEmployee();
						emp[count]->setEmployee(emp_id, emp_name, emp_age, emp_salary);
						((PartTimeEmployee *)emp[count])->setHoursWorked(emp_hours_worked);
						count++;
					}
				}
			}

			break;

		case 2:
			for (int i = 0; i < count; i++)
			{
				cout << endl
					 << "-------Employee " << i + 1 << " details-------" << endl;
				emp[i]->display();
				cout << endl;
			}
			break;

		case 3:
			for (int i = 0; i < count; i++)
			{
				delete emp[i];
			}
			cout << endl
				 << "Deleted Successfully" << endl;
			count++;
			break;

		case 4:
			cout << endl
				 << "Exiting..." << endl;
			break;

		default:
			cout << "Enter valid input" << endl;
		}
	} while (choice != 4);

	return 0;
}