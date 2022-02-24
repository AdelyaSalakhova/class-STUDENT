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
	} // Конструктор создания объекта.

	void GetWorkInfo() {
		cout << "Место работы : " << organization << endl;
		cout << "Занимаемая должность : " << position << endl;
		cout << "Стаж работы : " << experience << endl;
		cout << "Заработная плата : " << salary << endl;
	}

	void SetPosition(string position) {
		this->position = position;
	}

	void SetSalary(double plus_salary) {
		salary = salary + plus_salary;
	}

	void GetPersonalInfo() {
		cout << "Ф.И.О : " << name << endl;
		cout << "Пол : " << gender << endl;
		cout << "Возраст : " << age << endl;
	}

	void SalaryComparsion(EMPLOYEE& second) {
		if (*this < second) {
			cout << second.name << " has better salary than " << this->name << endl;
		}
		else if (*this == second) {
			cout << second.name << " has equal salary with " << this->name << endl;
		}
		else cout << this->name << " has better salary than " << second.name << endl;
	}// Сравнение заработных плат.
	
	bool operator< (EMPLOYEE const& other) {
		return this->salary < other.salary;
	}// Перегрузка оператора, сравнение заработных плат.
    
	bool operator == (EMPLOYEE const& other) {
		return this->salary == other.salary;
	}// перегрузка оператора ==, приверка заработных плат на равенство.

	EMPLOYEE& operator = (EMPLOYEE const& other) {
		this->position = other.position;
		return *this;
	}

	void PositionAssignment(EMPLOYEE& second) {
		*this = second ;
	}// Присвоение одинаковых должностей двум объектам.
    
	static int GetCount() {
		return count;
	}// Статический метод, получение количества сотрудников.

	~EMPLOYEE() {
		count--;
	}// Деструктор.
};

int EMPLOYEE::count = 0; // Инициализация статической переменной вне класса.

int main() {

	setlocale(LC_ALL, "Russian");
	EMPLOYEE obj1("Gallinger_Diana", 18, "REU", "Active", 10000, 1, 'F');
	EMPLOYEE obj2("Salakhova_Adelya", 18, "REU", "Student", 10000, 1, 'F');
	EMPLOYEE obj3("Shirokov_Roman", 18, "REU", "Student", 15000, 100, 'M');

	EMPLOYEE objects[3] = { obj1, obj2, obj3 };// Создание массива объектов класса EMPLOYEE.

	cout << "Насчитывается " <<  EMPLOYEE::GetCount() << " сотрудника." << endl << endl; // вывод количества объектов.
	for (int i = 0; i < 3; i++) {
		 objects[i].GetPersonalInfo();
		 objects[i].GetWorkInfo();
	}// Вывод информации о каждом объекте.
	
	objects[0].SalaryComparsion(objects[2]); // Сравнение заработных плат двух объектов.
	cout << endl;
	objects[0].PositionAssignment(objects[2]); // Присвоение объекту должности другого объекта.
	cout << endl;
	objects[0].SetSalary(2734); //  Увеличение текущей заработной платы объекта на 2734.
	cout << endl;
	for (int i = 0; i < 3; i++) {
		objects[i].GetPersonalInfo();
		objects[i].GetWorkInfo();
	}// Вывод информации о каждом объекте.
}
