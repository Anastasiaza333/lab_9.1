#include <iomanip>
#include <iostream>
#include <Windows.h>

using namespace std;

enum Specialty { ���������, �����������, ��������������������, Գ����������������, ��������������� };

string specialty[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������",
"������� ��������" };

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
	cout << "������ ����� ��������:\n"; cin >> number;

	Student* p = new Student[number];

	int countPhysics = 0;
	double average_1 = 0;
	double average_2 = 0;
	double average_3 = 0;


	int menuItem = 0;
	

	do
	{
		cout << "������� ��:\n"
			<< "1. ��������� ���\n"
			<< "2. ������� �� ����� ���\n"
			<< "3. ������� ��� � ������ ��������\n"
			<< "4. ʳ������ ��������,�� �������� � ������ \"4\" ��� \"5\"  :\n"
			<< "0. ��������� ������ ��������\n";
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
			cout << "ʳ������ ��������,�� �������� � ������ \"4\" ��� \"5\": " << countPhysics << "\n";
			cout << "\n";
			break;
		case 0:
			break;
		default:
			cout << "����������� �������!\n";
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
		cout << "������� �" << i + 1 << ":\n";
		cin.sync();
		cout << "�������: "; cin >> p[i].Surname;
		cout << "����: "; cin >> p[i].course;
		cout << "������������ (��������� - 0, ����������� - 1, ���������� �� �������� - 2, Գ���� �� ����������� - 3, ������� �������� - 4): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << "������ � ������: "; cin >> p[i].physics;
		cout << "������ � ����������: "; cin >> p[i].mathematics;
		cout << "������ � �����������: "; cin >> p[i].informatics; cout << "\n";
	}
}
void Print(Student* p, const int number)
{
	cout << "+-----------------------------------------------------------------------------------------------------------+"
		<< "\n";
	cout << "| �   |   �������   |   ����   |       ������������       |   Գ����   |   ����������   |   �����������   |"
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
	    cout << "���������� " <<"������� ���: " << average_1 << "\n";
		cout << "�����������"   <<   "������� ���: " << average_2 << "\n";
		cout << "Գ���� " <<  "������� ���: " << average_3 << "\n";

}
