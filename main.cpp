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
		cout << "С какими операциями вы хотите работать?" << endl << "1) Унарные" << endl
			<< "2) Бинарные" << endl << "3) Выпустите меня отсюда" << endl << "Ваш выбор: ";
		cin >> choise;
		switch (choise) {
		case 1: {
			int unChoise;
			do {
				system("CLS");
				cout << "Что вы хотите сделать?" << endl << "1) Увеличть значение x, y или z на любое ваше число" << endl
					<< "2) Увеличить значение x, y или z на максимально число среди них" << endl
					<< "3) Уменьшить значение x, y или z на любое ваше число" << endl
					<< "4) Уменьшить значение x, y или z на минимально число среди них" << endl
					<< "5) Выйти из унарных операций" << endl << "Ваш выбор: ";
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
					cout << "Введите корректный номер операции!" << endl;
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
				cout << "Что вы хотите сделать?" << endl
					<< "1) Изменение первой очереди за счёт второй" << endl
					<< "2) Изменение значений первой очереди произвольным образом" << endl
					<< "3) Выйти из бинарных операций" << endl
					<< "Ваш выбор: ";
				cin >> choise;
				switch (choise) {
					//////////////////////////////////////////////////////////////////////
				case 1: {
					cout << "Что вы хотите сделать?" << endl
						<< "1) Сложить очереди" << endl
						<< "2) Вычесть из первой очереди вторую" << endl
						<< "3) Перемножить очереди" << endl
						<< "4) Поделить первую очередь на вторую" << endl
						<< "Ваш выбор: ";
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
					cout << "Что вы хотите сделать?" << endl
						<< "1) Сложить значения очереди с вашим значением" << endl
						<< "2) Вычесть из значений первой ваше значение" << endl
						<< "3) Перемножить значение очереди на ваше значение" << endl
						<< "4) Поделить очередь на ваше значение" << endl
						<< "Ваш выбор: ";
					cin >> choise;
					int val;
					cout << "Введите ваше значение: " << endl;
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
					cout << "Введите корректный номер операции!" << endl;
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
			cout << "Введите корректный номер операции!" << endl;
			system("pause");
			exit = false;
			break;
		}
		}
	} while (exit == false);
}