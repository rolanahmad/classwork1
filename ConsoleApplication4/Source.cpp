#include <iostream>
#include <time.h>

using namespace std;
enum specialty {
	specialty1,
	specialty2,
	specialty3,
	specialty4
};

struct associate {
	char *surname;
	int *age;
	specialty specialty;
	double *salary;
};

struct factory {
	int average_age;
	double average_salary;
	associate *associate_mass;
};

/*
���������� �� N ������� ������ �������� ������� ���������� ���� :
�������, ������� �������, �������������, ������� �����.
������ ���������� �� �������, ��������� ���������� �������� � �������.
���������� ��� ��������.
*/

void main() {

}
