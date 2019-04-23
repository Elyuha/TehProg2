#include <iostream>
#include <ctime>
#include "Coordinates.h"
#include "cyclicQueue.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int choise;
	Coordinates cor;
	CyclicQ qu;
	int num = rand() % 25 + 5;
	for (int i = num; i > 0; i--) {
		int c = rand() % 100 + 1;
		qu.add(c);
	}
	bool exit = false;
	do {
		system("CLS");
		cout << "� ������ ���������� �� ������ ��������?" << endl << "1) �������" << endl
			<< "2) ��������" << endl << "3) ��������� ���� ������" << endl << "��� �����: ";
		cin >> choise;
		switch (choise) {
		case 1: {
			int unChoise;
			do {
				system("CLS");
				cout << "��� �� ������ �������?" << endl << "1) �������� �������� x, y ��� z �� ����� ���� �����" << endl
					<< "2) ��������� �������� x, y ��� z �� ����������� ����� ����� ���" << endl
					<< "3) ��������� �������� x, y ��� z �� ����� ���� �����" << endl
					<< "4) ��������� �������� x, y ��� z �� ���������� ����� ����� ���" << endl
					<< "5) ����� �� ������� ��������" << endl << "��� �����: ";
				cin >> unChoise;
				switch (unChoise) {
				case 1: {
					++cor;
					cor.pin();
					exit = true;
					break;
				}
				case 2: {
					cor++;
					cor.pin();
					exit = true;
					break;
				}
				case 3: {
					--cor;
					cor.pin();
					exit = true;
					break;
				}
				case 4: {
					cor--;
					cor.pin();
					exit = true;
					break;
				}
				case 5: {
					exit = false;
					break;
				}
				default: {
					cout << "������� ���������� ����� ��������!" << endl;
					system("pause");
					exit = true;
					break;
				}
				}
			}
			while (exit == true);
			exit = false;
			break;
		}
				//////////////////////////////////////////////////////////////////////
		case 2: {
			CyclicQ other_qu;
			for (int i = num; i > 0; i--) {
				int c = rand() % 100 + 1;
				other_qu.add(c);
			}
			do {
				system("CLS");
				qu.pin();
				other_qu.pin();
				cout << "��� �� ������ �������?" << endl
					<< "1) ��������� ������ ������� �� ���� ������" << endl
					<< "2) ��������� �������� ������ ������� ������������ �������" << endl
					<< "3) ����� �� �������� ��������" << endl
					<< "��� �����: ";
				cin >> choise;
				switch (choise) {
					//////////////////////////////////////////////////////////////////////
				case 1: {
					cout << "��� �� ������ �������?" << endl
						<< "1) ������� �������" << endl
						<< "2) ������� �� ������ ������� ������" << endl
						<< "3) ����������� �������" << endl
						<< "4) �������� ������ ������� �� ������" << endl
						<< "��� �����: ";
					cin >> choise;
					switch (choise) {
					case 1: {
						qu = qu + other_qu;
						break;
					}
					case 2: {
						qu = qu - other_qu;
						break;
					}
					case 3: {
						qu = qu * other_qu;
						break;
					}
					case 4: {
						qu = qu / other_qu;
						break;
					}
					}
					exit = true;
					break;
				}
				case 2: {
					//////////////////////////////////////////////////////////////////////
					cout << "��� �� ������ �������?" << endl
						<< "1) ������� �������� ������� � ����� ���������" << endl
						<< "2) ������� �� �������� ������ ���� ��������" << endl
						<< "3) ����������� �������� ������� �� ���� ��������" << endl
						<< "4) �������� ������� �� ���� ��������" << endl
						<< "��� �����: ";
					cin >> choise;
					int val;
					cout << "������� ���� ��������: " << endl;
					cin >> val;
					switch (choise) {
					case 1: {
						qu += val;
						break;
					}
					case 2: {
						qu -= val;
						break;
					}
					case 3: {
						qu *= val;
						break;
					}
					case 4: {
						qu /= val;
						break;
					}
					}
					exit = true;
					break;
				}
						//////////////////////////////////////////////////////////////////////
				case 3: {

					exit = false;
					break;
				}
				default: {
					cout << "������� ���������� ����� ��������!" << endl;
					system("pause");
					exit = true;
					break;
				}
				}
			} while (exit == true);
			exit = false;
			break;
		}
		case 3: {
			exit = true;
			break;
		}
		default: {
			cout << "������� ���������� ����� ��������!" << endl;
			system("pause");
			exit = false;
			break;
		}
		}
	} while (exit == false);
}