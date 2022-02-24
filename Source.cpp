#include <iostream>
#include <string>

using namespace std;

class EMPLOYEE {

private:

	string organization;
	string position;
	double experience;
	string name;
	char gender;
	int age;
	double salary;
	static int count;

public:

	EMPLOYEE(string uname, int uage, string uorganization, string uposition, double usalary, double uexperience, char ugender) : name(uname), age(uage), organization(uorganization), position(uposition), salary(usalary), experience(uexperience), gender(ugender)
	{
		count++;
	} // ����������� �������� �������.

	void GetWorkInfo() {
		cout << "����� ������ : " << organization << endl;
		cout << "���������� ��������� : " << position << endl;
		cout << "���� ������ : " << experience << endl;
		cout << "���������� ����� : " << salary << endl;
	}

	void SetPosition(string position) {
		this->position = position;
	}

	void SetSalary(double plus_salary) {
		salary = salary + plus_salary;
	}

	void GetPersonalInfo() {
		cout << "�.�.� : " << name << endl;
		cout << "��� : " << gender << endl;
		cout << "������� : " << age << endl;
	}

	void SalaryComparsion(EMPLOYEE& second) {
		if (*this < second) {
			cout << second.name << " has better salary than " << this->name << endl;
		}
		else if (*this == second) {
			cout << second.name << " has equal salary with " << this->name << endl;
		}
		else cout << this->name << " has better salary than " << second.name << endl;
	}// ��������� ���������� ����.
	
	bool operator< (EMPLOYEE const& other) {
		return this->salary < other.salary;
	}// ���������� ���������, ��������� ���������� ����.
    
	bool operator == (EMPLOYEE const& other) {
		return this->salary == other.salary;
	}// ���������� ��������� ==, �������� ���������� ���� �� ���������.

	void PositionAssignment(EMPLOYEE& second) {
		this->position = second.position;
	}// ���������� ���������� ���������� ���� ��������.
    
	static int GetCount() {
		return count;
	}// ����������� �����, ��������� ���������� �����������.

	~EMPLOYEE() {
		count--;
	}// ����������.
};

int EMPLOYEE::count = 0; // ������������� ����������� ���������� ��� ������.

int main() {

	setlocale(LC_ALL, "Russian");
	EMPLOYEE obj1("Gallinger_Diana", 18, "REU", "Active", 10000, 1, 'F');
	EMPLOYEE obj2("Salakhova_Adelya", 18, "REU", "Student", 10000, 1, 'F');
	EMPLOYEE obj3("Shirokov_Roman", 18, "REU", "Student", 15000, 100, 'M');

	EMPLOYEE objects[3] = { obj1, obj2, obj3 };// �������� ������� �������� ������ EMPLOYEE.

	cout << "������������� " <<  EMPLOYEE::GetCount() << " ����������." << endl << endl; // ����� ���������� ��������.
	for (int i = 0; i < 3; i++) {
		 objects[i].GetPersonalInfo();
		 objects[i].GetWorkInfo();
	}// ����� ���������� � ������ �������.
	
	objects[0].SalaryComparsion(objects[2]); // ��������� ���������� ���� ���� ��������.
	cout << endl;
	objects[0].PositionAssignment(objects[2]); // ���������� ������� ��������� ������� �������.
	cout << endl;
	objects[0].SetSalary(2734); //  ���������� ������� ���������� ����� ������� �� 2734.
	cout << endl;
	for (int i = 0; i < 3; i++) {
		objects[i].GetPersonalInfo();
		objects[i].GetWorkInfo();
	}// ����� ���������� � ������ �������.
}