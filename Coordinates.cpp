#include <iostream>
#include "Coordinates.h"

using namespace std;

Coordinates::Coordinates() {
	x = new int; 
	*x = 0;
	y = new int;
	*y = 0;
	z = new int;
	*z = 0;
}

Coordinates::Coordinates(int val1, int val2, int val3) {
	x = new int;
	y = new int;
	z = new int;
	*x = val1;
	*y = val2;
	*z = val3;
}

Coordinates::~Coordinates() {
	delete x;
	delete y;
	delete z;
}

Coordinates::Coordinates(const Coordinates &obj) {
	x = new int;
	*x = *obj.x;
	y = new int;
	*y = *obj.y;
	z = new int;
	*z = *obj.z;
}

void Coordinates::pin() {
	cout << endl << endl << "Текущие значения координат:" << endl;
	cout << "X = " << *x << endl 
		 << "Y = " << *y << endl 
		 << "Z = " << *z << endl;
	system("pause");
}

Coordinates &Coordinates::operator++() {
	int choise;
	int value;
	cout << "Какую координату вы хотите увеличить?" << endl << "1) X" << endl << "2) Y" << endl << "3) Z" << endl
		<< "Ваш выбор: ";
	cin >> choise;
	cout << "Введите значение на которое хотите увеличить координату: ";
	cin >> value;
	switch (choise) {
	case 1: {
		*x += value;
		break;
	}
	case 2: {
		*y += value;
		break;
	}
	case 3: {
		*z += value;
		break;
	}
	}
	return *this;
}

Coordinates Coordinates::operator--(int) {
	Coordinates ob(*this);
	int choise;
	cout << "Какую координату вы хотите уменьшить?" << endl << "1) X" << endl << "2) Y" << endl << "3) Z" << endl
		<< "Ваш выбор: ";
	cin >> choise;
	switch (choise) {
	case 1: {
		(*x > *y) ? ((*y > *z) ? (*x -= *z) : (*x -= *y)) : ((*x > *z) ? (*x -= *z) : (*x -= *x));
		break;
	}
	case 2: {
		(*x > *y) ? ((*y > *z) ? (*y -= *z) : (*y -= *y)) : ((*x > *z) ? (*y -= *z) : (*y -= *x));
		break;
	}
	case 3: {
		(*x > *y) ? ((*y > *z) ? (*z -= *z) : (*z -= *y)) : ((*x > *z) ? (*z -= *z) : (*z -= *x));
		break;
	}
	}
	return ob;
}

Coordinates operator++(Coordinates &op, int) {
	Coordinates ob(op);
	int choise;
	cout << "Какую координату вы хотите увеличить?" << endl << "1) X" << endl << "2) Y" << endl << "3) Z" << endl
		<< "Ваш выбор: ";
	cin >> choise;
	switch (choise)
	{
	case 1: {
		(*op.x > *op.y) ? ((*op.x > *op.z) ? (*op.x += *op.x) : (*op.x += *op.z)) : ((*op.y > *op.z) ? (*op.x += *op.y) : (*op.x += *op.z));
		break;
	}
	case 2: {
		(*op.x > *op.y) ? ((*op.x > *op.z) ? (*op.y += *op.x) : (*op.y += *op.z)) : ((*op.y > *op.z) ? (*op.y += *op.y) : (*op.y += *op.z));
		break;
	}
	case 3: {
		(*op.x > *op.y) ? ((*op.x > *op.z) ? (*op.z += *op.x) : (*op.z += *op.z)) : ((*op.y > *op.z) ? (*op.z += *op.y) : (*op.z += *op.z));
		break;
	}
	}
	return ob;
}

Coordinates &operator--(Coordinates &op) {
	int choise;
	int value;
	cout << "Какую координату вы хотите уменьшить?" << endl << "1) X" << endl << "2) Y" << endl << "3) Z" << endl
		<< "Ваш выбор: ";
	cin >> choise;
	cout << "Введите значение на которое хотите увеличить координату: ";
	cin >> value;
	switch (choise) {
	case 1: {
		*op.x -= value;
		break;
	}
	case 2: {
		*op.y -= value;
		break;
	}
	case 3: {
		*op.z -= value;
		break;
	}
	}
	return op;
}