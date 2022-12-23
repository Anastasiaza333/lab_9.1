#include <iomanip>
#include <iostream>
#include <Windows.h>

using namespace std;

enum Specialty { КомпНауки, Інформатика, МатематикаТаЕкономіка, ФізикаТаІнформатика, ТрудовеНавчання };

string specialty[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика",
"Трудове навчання" };

struct Student
{
	string Surname;
	short unsigned course;
	Specialty specialty;
	short unsigned physics;
	short unsigned mathematics;
	short unsigned informatics;
};

void Create(Student* p, const int number);
void Print(Student* p, const int number);
void CountStudents(Student* p, const int number, int& countPhysics);
void Average(Student* p, const int number, double& average_1, double& average_2, double& average_3);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number;
	cout << "Введіть число студентів:\n"; cin >> number;

	Student* p = new Student[number];

	int countPhysics = 0;
	double average_1 = 0;
	double average_2 = 0;
	double average_3 = 0;


	int menuItem = 0;
	

	do
	{
		cout << "Виберіть дію:\n"
			<< "1. Заповнити дані\n"
			<< "2. Вивести на екран дані\n"
			<< "3. Середній бал з кожноо предмету\n"
			<< "4. Кількість студентів,які отримали з фізики \"4\" або \"5\"  :\n"
			<< "0. Завершити роботу програми\n";
		cin >> menuItem; cout << "\n";

		switch (menuItem)
		{
		case 1:
			Create(p, number);
			cout << "\n";
			break;
		case 2:
			Print(p, number);
			cout << "\n";
			break;
		case 3:
			 Average( p, number, average_1, average_2,  average_3);
			cout << "\n";
			break;
		case 4:
			CountStudents(p, number, countPhysics);
			cout << "Кількість студентів,які отримали з фізики \"4\" або \"5\": " << countPhysics << "\n";
			cout << "\n";
			break;
		case 0:
			break;
		default:
			cout << "Нерозпізнана команда!\n";
		}
	} while (menuItem != 0);

	cin.get();
	return 0;
}

void Create(Student* p, const int number)
{
	int specialty;
	for (int i = 0; i < number; i++)
	{
		cout << "Студент №" << i + 1 << ":\n";
		cin.sync();
		cout << "Прізвище: "; cin >> p[i].Surname;
		cout << "Курс: "; cin >> p[i].course;
		cout << "Спеціальність (КомпНауки - 0, Інформатика - 1, Математика та економіка - 2, Фізика та інформатика - 3, Трудове навчання - 4): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << "Оцінка з фізики: "; cin >> p[i].physics;
		cout << "Оцінка з математики: "; cin >> p[i].mathematics;
		cout << "Оцінка з інформатики: "; cin >> p[i].informatics; cout << "\n";
	}
}
void Print(Student* p, const int number)
{
	cout << "+-----------------------------------------------------------------------------------------------------------+"
		<< "\n";
	cout << "| №   |   Прізвище   |   Курс   |       Спеціальність       |   Фізика   |   Математика   |   Інформатика   |"
		<< "\n";
	cout << "+-----------------------------------------------------------------------------------------------------------+"
		<< "\n";
	cout << fixed;
	for (int i = 0; i < number; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << setw(2) << " ";
		cout << "| " << setw(9) << left << p[i].Surname << setw(6)
			<< "| " << setw(5) << left << p[i].course << setw(4) << " "
			<< "| " << setw(10) << right << specialty[p[i].specialty] << setw(10) << " "
			<< "| " << setw(6) << left << p[i].physics << setw(5) << " "
			<< "| " << setw(8) << left << p[i].mathematics << setw(7) << " "
			<< "| " << setw(8) << left << p[i].informatics << setw(8) << " " << "|" << "\n";
		cout << "+-----------------------------------------------------------------------------------------------------------+"
			<< "\n";
	}
}

void CountStudents(Student* p, const int number, int& countPhysics)
{
	for (int i = 0; i < number; i++)
	{
		if (p[i].physics == 4 || p[i].physics == 5)
			countPhysics++;

	}
}

void Average(Student* p, const int number,double& average_1, double& average_2, double& average_3)
{
	int index = 0;

	for (int j = 1; j < number; j++)
	{
		if (j + 2 != number){
		average_1 = (p[j].mathematics + p[j + 1].mathematics + p[j + 2].mathematics) / (1. * number);
		average_2 = (p[j].informatics + p[j + 1].informatics + p[j + 2].informatics) / (1. * number);
		average_3 = (p[j].physics + p[j + 1].physics + p[j + 2].physics) / (1. * number);
			}

	}
	    cout << "Математика " <<"середній бал: " << average_1 << "\n";
		cout << "Інформатика"   <<   "середній бал: " << average_2 << "\n";
		cout << "Фізика " <<  "середній бал: " << average_3 << "\n";

}
