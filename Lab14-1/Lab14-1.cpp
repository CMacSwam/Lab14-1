#include <iostream>
#include <string>

using namespace std;

double average(double* a, int size);
double maximum(double* a, int size);
double minimum(double* a, int size);
int locationMax(double* a, int size);
int locationMin(double* a, int size);

int main() {

	cout << "Enter size of array: ";
	int size;
	cin >> size;

	double* pointer_array = new double[size];

	cout << "Enter " << size << " floating-point values: ";

	for(int i = 0; i < size; i++){
		cin >> *(pointer_array + i);
	}

	cout << "\nAverage is " << average(pointer_array, size) << endl;
	cout << "Minimum value is element #" << locationMin(pointer_array, size) << ": " << minimum(pointer_array, size) << endl;
	cout << "Maximum value is element #" << locationMax(pointer_array, size) << ": " << maximum(pointer_array, size) << endl;

}


double average(double* a, int size) {
	if (size == 0) return 0;

	double total = 0;

	for (int i = 0; i < size; i++) {
		total = total + *a;
		a++;
	}
	total = total / size;
	return total;
}

double maximum(double* a, int size) {
	double* pointer = a;
	if (size == 0) return NULL;

	double maximum = 0;

	for (int i = 0; i < size; i++) {
		if (*pointer > maximum) {
			maximum = *pointer;
		}
		pointer++;
	}

	return maximum;
}

double minimum(double* a, int size) {
	double* pointer = a;
	if (size == 0) return NULL;

	double minimum = 1000000000;

	for (int i = 0; i < size; i++) {
		if (*pointer < minimum) {
			minimum = *pointer;
		}
		pointer++;
	}

	return minimum;
}

int locationMax(double* a, int size) {
	int location = 0;
	double* pointer = a;
	double max = 0;
	for (int i = 0; i < size; i++) {
		if (*pointer > max) {
			*pointer = max;
			location = i;
		}
		pointer++;
	}
	return location;
}

int locationMin(double* a, int size) {
	int location = 0;
	double* pointer = a;
	double min = *pointer;
	

	for (int i = 0; i < size; i++) {
		if (*pointer < min) {
			min = *pointer;
			location = i;
		}
		pointer++;
	}
	return location;
}