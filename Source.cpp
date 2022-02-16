#include <iostream>

using namespace std;

const int LNAME = 25;


class STUDENT {

private :
    // Принцип инкапсуляции, доступ к полям будет доступен только через интерфейс.
    char name [LNAME];      
    int age;                         
    float grade;                  

public :
    
    STUDENT() 
    {
        for (int i = 0; i < 25; i++) 
        {
           name[i] = 0;
        }
        age = 0;
        grade = 0;
    }// Конструктор класса, позволяющий инициализировать поля изначально нормальными значенниями.

    char* GetName() 
    {
        return name;
    }// Гетер имени.        

    int GetAge() const 
    {
        return age;
    }// Гетер возраста. 

    float GetGrade() const 
    {
        return grade;
    }// Гетер рейтинга.

    void SetName(char* name) 
    {
        int c = 0;
        while (*name != '\0') 
        {//При помощи цикла while, пока мы не дойдем до 0 терминатора, мы присваиваем массиву char каждый введенный пользователем символ, 
         //затем перемещаем указатель на следующий символ.
            this->name[c] = *name;
            name++; 
            c++;
        }
    }// Сетер имени.

    void SetAge(int age) 
    {
        this->age = age;
    }// Сетер возраста.          

    void SetGrade(float grade) 
    {
        this->grade = grade;
    }// Сетер рейтинга.   

    void Set(char* name, int age, float grade) 
    {
        int c = 0;
        while (*name != '\0') 
        {
            this->name[c] = *name;
            name++;
            c++;
        }
        this->age = age;
        this->grade = grade;
    }// Общий сетер.          

    void Show() 
    {
        cout << "Имя студента : " << name << endl;
        cout << "Возраст студента : " << age << endl;
        cout << "Рейтинг студента : " << grade << endl;
    }// Вывод всех трех полей на экран.                            
};

int main() 
{
    setlocale(LC_ALL, "russian");
    STUDENT student; // Создание объекта класса STUDENT.
    char name[25];
    int age;
    float grade;
    cout << "Введите имя, не превыщающее 24 символа латиницей." << endl;
    cin >> name;
    cout << "Введите возраст." << endl;
    cin >> age;
    cout << "Введите рейтинг." << endl;
    cin >> grade;
    
    student.SetName(name);
    cout << "Имя студента : " << student.GetName() << endl;
    student.SetAge(age);
    cout << "Возраст студента : " << student.GetAge() << endl;
    student.SetGrade(grade);
    cout << "Рейтинг студента : " << student.GetGrade() << endl << endl;
    
    cout << "Функционал общего set и show." << endl;
    student.Set(name, age, grade);
    student.Show();
    
    return 0;
}