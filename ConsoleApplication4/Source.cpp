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
»нформаци€ по N заводам города задаетс€ строкой следующего вида :
фамили€, средний возраст, специальность, средний оклад.
¬вести информацию по заводам, посчитать количество слесарей и токарей.
Ќапечатать эти значени€.
*/

void main() {

}
