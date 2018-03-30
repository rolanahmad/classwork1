#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//SetConsoleTextAttribute(hConsole, 12); �������
//SetConsoleTextAttribute(hConsole, 15); �����

enum specialty {
	slesar,
	tokar
};

struct associate {
	char *surname;
	int age;
	specialty specialty;
	double salary;
};

struct factory {
	char *factory_name;
	int average_age;
	long double average_salary;
	associate *associate_mass;
	int associate_colvo;
};

char *name_factory_mass[5] = { "�����Company" , "�������Comany" , "��������������", "LG","Nokia"};

/*
���������� �� N ������� ������ �������� ������� ���������� ���� :
�������, ������� �������, �������������, ������� �����.
������ ���������� �� �������, ��������� ���������� �������� � �������.
���������� ��� ��������.
*/

//��������� �.�.�
void generate_associate(associate *associate);

int count_speciality(factory *factory, specialty specialty);

void main() {
	srand(time(0));
	rand();
	system("chcp 1251");
	system("cls");

	//int factory_colvo;
	//cout << "���������� ������� ���������� �������: ";
	//cin >> factory_colvo;

	factory *factorys = new factory[5];

	for (int i = 0; i < 5; i++) {
		(factorys + i)->associate_colvo = 1 + rand() % 99;
		(factorys + i)->factory_name = name_factory_mass[i];
	}

	for (int i = 0; i < 5; i++) {
		(factorys + i)->associate_mass = new associate[(factorys + i)->associate_colvo];
		(factorys + i)->average_age = 0;
		(factorys + i)->average_salary = 0;

		for (int j = 0; j < (factorys + i)->associate_colvo; j++)
		{
			generate_associate(&(factorys + i)->associate_mass[j]);
			(factorys + i)->average_age += (factorys + i)->associate_mass[j].age ; //������� �������
			(factorys + i)->average_salary += (factorys + i)->associate_mass[j].salary; //������� �����

		}

		(factorys + i)->average_age /= (factorys + i)->associate_colvo;
		(factorys + i)->average_salary /= (factorys + i)->associate_colvo;
	}
	
	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(hConsole, 12);
		cout << "#" << i + 1 << "." <<
			(factorys + i)->factory_name << endl;
		cout << "------------------------------------------" << endl;
		cout << "���������� �����������: "<< (factorys + i)->associate_colvo << endl;
		cout << "������� ������� �����������: " << (factorys + i)->average_age<<endl;
		cout << "������� �������� �����������: " << (factorys + i)->average_salary << endl;
		cout << "------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 15);

		for (int j = 0; j < (factorys +i)->associate_colvo; j++)
		{
			cout << "#" << j + 1 << "." << " " <<
				(factorys + i)->associate_mass[j].surname << " " <<
				(factorys + i)->associate_mass[j].age << " " <<
				(factorys + i)->associate_mass[j].salary << " " <<
				(factorys + i)->associate_mass[j].specialty << " " << endl;
		}
		cout << "------------------------------------------" << endl;
		cout << "���������� ��������: " << count_speciality((factorys+i),slesar) << endl;
		cout << "���������� �������: " << count_speciality((factorys+i), tokar) << endl;
		cout << "------------------------------------------" << endl;
	}

	
	for (int i = 0; i < 5; i++) {
		char name[30]="C://1//";
		strcat(name, (factorys + i)->factory_name);
		strcat(name, ".txt");
		cout << name << endl;
		ofstream offile;
		offile.open(name);

		offile << "#" << i + 1 << "." <<
			(factorys + i)->factory_name << endl;
		offile << "------------------------------------------" << endl;
		offile << "���������� �����������: " << (factorys + i)->associate_colvo << endl;
		offile << "������� ������� �����������: " << (factorys + i)->average_age << endl;
		offile << "������� �������� �����������: " << (factorys + i)->average_salary << endl;
		offile << "------------------------------------------" << endl;


		for (int j = 0; j < (factorys + i)->associate_colvo; j++)
		{
			offile << "#" << j + 1 << "." << " " <<
				(factorys + i)->associate_mass[j].surname << " " <<
				(factorys + i)->associate_mass[j].age << " " <<
				(factorys + i)->associate_mass[j].salary << " " <<
				(factorys + i)->associate_mass[j].specialty << " " << endl;
		}
		offile << "------------------------------------------" << endl;
		offile << "���������� ��������: " << count_speciality((factorys + i), slesar) << endl;
		offile << "���������� �������: " << count_speciality((factorys + i), tokar) << endl;
		offile << "------------------------------------------" << endl;

		offile.close();
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void generate_associate(associate *associate) {

	associate->surname = new char[8];

	for (int i = 0; i < 3; i++) {
		if(i==0)
			associate->surname[i] = (char)65 + rand() % 25;
		else
			associate->surname[i] = (char)97 + rand() % 25;
	}

	associate->surname[3] = ' ';
	associate->surname[4] = (char)65 + rand() % 25;
	associate->surname[5] = '.';

	associate->surname[6] = (char)65 + rand() % 25;
	associate->surname[7] = '.';

	associate->surname[8] = '\0';

	associate->salary = 40000 + rand() % 500000;

	associate->age = 18 + rand() % 52;

	associate->specialty = specialty(0 + rand() % 2);
}

int count_speciality(factory *factory, specialty specialty) {
	int sum = 0;
	for (int i = 0; i < factory->associate_colvo; i++) {
		if (specialty == factory->associate_mass[i].specialty) {
			sum++;
		}

	}
	return sum;
}