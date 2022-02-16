#include <iostream>

using namespace std;

const int LNAME = 25;


class STUDENT {

private :
    // ������� ������������, ������ � ����� ����� �������� ������ ����� ���������.
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
    }// ����������� ������, ����������� ���������������� ���� ���������� ����������� �����������.

    char* GetName() 
    {
        return name;
    }// ����� �����.        

    int GetAge() const 
    {
        return age;
    }// ����� ��������. 

    float GetGrade() const 
    {
        return grade;
    }// ����� ��������.

    void SetName(char* name) 
    {
        int c = 0;
        while (*name != '\0') 
        {//��� ������ ����� while, ���� �� �� ������ �� 0 �����������, �� ����������� ������� char ������ ��������� ������������� ������, 
         //����� ���������� ��������� �� ��������� ������.
            this->name[c] = *name;
            name++; 
            c++;
        }
    }// ����� �����.

    void SetAge(int age) 
    {
        this->age = age;
    }// ����� ��������.          

    void SetGrade(float grade) 
    {
        this->grade = grade;
    }// ����� ��������.   

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
    }// ����� �����.          

    void Show() 
    {
        cout << "��� �������� : " << name << endl;
        cout << "������� �������� : " << age << endl;
        cout << "������� �������� : " << grade << endl;
    }// ����� ���� ���� ����� �� �����.                            
};

int main() 
{
    setlocale(LC_ALL, "russian");
    STUDENT student; // �������� ������� ������ STUDENT.
    char name[25];
    int age;
    float grade;
    cout << "������� ���, �� ����������� 24 ������� ���������." << endl;
    cin >> name;
    cout << "������� �������." << endl;
    cin >> age;
    cout << "������� �������." << endl;
    cin >> grade;
    
    student.SetName(name);
    cout << "��� �������� : " << student.GetName() << endl;
    student.SetAge(age);
    cout << "������� �������� : " << student.GetAge() << endl;
    student.SetGrade(grade);
    cout << "������� �������� : " << student.GetGrade() << endl << endl;
    
    cout << "���������� ������ set � show." << endl;
    student.Set(name, age, grade);
    student.Show();
    
    return 0;
}