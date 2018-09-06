#include"ע�ͼ�����.h"
#include"stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include<conio.h>
using namespace std;
struct Drink {
	Drink(float pr, string n);
	string name;
	float price;
	int account;
};
class Vending {
public:
	Vending();

	//��������ռ䣨ջ�ռ䣩 
	//���ڴ洢��Ʒ����
	inline void showStorage() const {    
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*                ����Ա����ϵͳ             *" << endl;
		cout << "*********************************************" << endl;
		cout << "���֣�" << m_cola->account << endl << "�̲裺" << m_milkT->account << endl;
		cout << "���裺" << m_T->account << endl;
	}

	//��������ռ䣨ջ�ռ䣩 
	//���ڴ洢��������
	inline void showSoldNum() const {    
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*                ����Ա����ϵͳ             *" << endl;
		cout << "*********************************************" << endl;
		cout << m_cola->name << endl << "��������" << m_soldCola << endl;
		cout << "���۶" << m_soldCola*(m_cola->price) << endl;
		cout << m_milkT->name << endl << "��������" << m_soldMilkTea << endl;
		cout << "���۶" << m_soldMilkTea*(m_milkT->price) << endl;
		cout << m_T->name << endl << "��������" << m_soldTea << endl;
		cout << "���۶" << m_soldTea*(m_T->price) << endl;
	}

	void addStore();
	void sellItem();
	void Menu();
	void VIP();

private:
	Drink *m_cola, *m_milkT, *m_T;
	int m_soldCola, m_soldMilkTea, m_soldTea;
};
Drink::Drink(float pr, string n)
	:name(n), price(pr), account(0) {}
Vending::Vending()
	: m_soldCola(0), m_soldMilkTea(0), m_soldTea(0)
{
	m_cola = new Drink(float(2.8), "����");
	m_milkT = new Drink(float(3.0), "�̲�");
	m_T = new Drink(float(3.5), "����");
}
//��Ʒ�ϼܹ��ܣ�����Ա������
void Vending::addStore() {    
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*                ����Ա����ϵͳ             *" << endl;
	cout << "*********************************************" << endl;
	cout << "��ѡ��Ҫ�ϼܵ���Ʒ��\n1.����\n2.�̲�\n3.����\n";
	int n, count;
	cin >> n;

	if (n > 3) {
		cout << "ѡ�����" << endl;
		return;
	}

	cout << "������Ҫ�ϼܵ�������";
	cin >> count;

	if (n == 1)
		m_cola->account += count;
	else if (n == 2)
		m_milkT->account += count;
	else if (n == 3)
		m_T->account += count;
	else {
		cout << "����ʧ��" << endl;
		return;
	}

	cout << "�������" << endl;
}
//���۽���
void Vending::sellItem() {   
	system("cls");
	cout << "1." << m_cola->name << "��" << endl;
	cout << "�۸�" << m_cola->price << ends << "��棺" << m_cola->account << (m_cola->account == 0 ? "�����꣩\n" : "\n");
	cout << "2." << m_milkT->name << "��" << endl;
	cout << "�۸�" << m_milkT->price << ends << "��棺" << m_milkT->account << (m_milkT->account == 0 ? "�����꣩\n" : "\n");
	cout << "3." << m_T->name << "��" << endl;
	cout << "�۸�" << m_T->price << ends << "��棺" << m_T->account << (m_T->account == 0 ? "�����꣩\n" : "\n");
	cout << "��ѡ��";
	int n = 0, num = 0;
	cin >> n;

	float price = 0;
	int acc = 0;
	if (n == 1) {
		price = m_cola->price;
		acc = m_cola->account;
	}
	else if (n == 2) {
		price = m_milkT->price;
		acc = m_milkT->account;
	}
	else if (n == 3) {
		price = m_T->price;
		acc = m_T->account;
	}

	do
	{
		if (num > 0)
			cout << "��治��" << endl;

		cout << "������������";
		cin >> num;
	} while (num > acc);

	price *= num;

	float pay = 0;
	do
	{
		if (pay > 0)
			cout << "֧������" << endl;

		cout << "��֧����";
		cin >> pay;
	} while (pay < price);

	cout << "�������" << endl;
	if (pay - price > 0)
		cout << "���㣺" << pay - price << endl;

	if (n == 1) {
		m_soldCola += num;
		m_cola->account -= num;
	}
	else if (n == 2) {
		m_soldMilkTea += num;
		m_milkT->account -= num;
	}
	else if (n == 3) {
		m_soldTea += num;
		m_T->account -= num;
	}
}
void Vending::VIP() {
	system("cls");
	cout << "1." << m_cola->name << "��" << endl;
	cout << "�۸�" << m_cola->price/2 << ends << "��棺" << m_cola->account << (m_cola->account == 0 ? "�����꣩\n" : "\n");
	cout << "2." << m_milkT->name << "��" << endl;
	cout << "�۸�" << m_milkT->price/2 << ends << "��棺" << m_milkT->account << (m_milkT->account == 0 ? "�����꣩\n" : "\n");
	cout << "3." << m_T->name << "��" << endl;
	cout << "�۸�" << m_T->price/2 << ends << "��棺" << m_T->account << (m_T->account == 0 ? "�����꣩\n" : "\n");
	cout << "��ѡ��";
	int n = 0, num = 0;
	cin >> n;

	float price = 0;
	int acc = 0;
	if (n == 1) {
		price = m_cola->price/2;
		acc = m_cola->account;
	}
	else if (n == 2) {
		price = m_milkT->price/2;
		acc = m_milkT->account;
	}
	else if (n == 3) {
		price = m_T->price/2;
		acc = m_T->account;
	}

	do
	{
		if (num > 0)
			cout << "��治��" << endl;

		cout << "������������";
		cin >> num;
	} while (num > acc);

	price *= num;

	float pay = 0;
	do
	{
		if (pay > 0)
			cout << "֧������" << endl;

		cout << "��֧����";
		cin >> pay;
	} while (pay < price);

	cout << "�������" << endl;
	if (pay - price > 0)
		cout << "���㣺" << pay - price << endl;

	if (n == 1) {
		m_soldCola += num;
		m_cola->account -= num;
	}
	else if (n == 2) {
		m_soldMilkTea += num;
		m_milkT->account -= num;
	}
	else if (n == 3) {
		m_soldTea += num;
		m_T->account -= num;
	}
}
//���˵�
void Vending::Menu() {   
	const string menu1 = "========�Զ�������========\n1.������Ա����\n2.���۽���\n3.VIP��½\n4.�˳�\n";
	const string menu2 = "========�Զ�������========\n*********************************************\n*                ����Ա����ϵͳ             *\n*********************************************\n1.��ʾ���\n2.��Ʒ�ϼ�\n3.���۲�ѯ\n4.������ҳ\n5.�˳�\n";
	const string menu3= "========�Զ�������========\n*********************************************\n*                VIP�������             *\n*********************************************\n1.VIP���۽���\n2.��������\n3.������ҳ\n4.�˳�\n";
	int n;
	while (true) {
		cout << menu1 << "��ѡ��";
		cin >> n;
		if (n == 1) {
			cout << "���������룺";
			int password;
			cin >> password;
			if (password != 123) {
				cout << "�������" << endl;
				continue;
			}
			system("cls");
			cout << menu2 << "��ѡ��";
			cin >> n;

			switch (n) {
			case 1: {
				showStorage();
				break;
			}
			case 2: {
				addStore();
				break;
			}
			case  3: {
				showSoldNum();
				break;
			}
			case 4: {
				Menu();
				break;
			}
			case 5: {
				exit(0);
				break;
			}

					 //ע���쳣����
			default: {   
				cout << "ѡ�����" << endl;
				return;
			}
			}
		}
		else if (n == 2) {
			system("cls");
			sellItem();
		}
		else if (n == 3) {
			system("cls");
			cout << "���������룺";
			int password;
			cin >> password;
			if (password != 123) {
				cout << "�������" << endl;
				continue;
				}
			cout << menu3 << "��ѡ��";
			cin >> n;

			switch (n) {
			case 1: {
				VIP();
				break;
				}
			case 3: {
				Menu();
				break;
			}
			case 4: {
				exit(0);
			}

					//ע���쳣����
			default: {
				cout << "ѡ�����" << endl;
				return;
				}
			}
		}
		
		else if(n==4)
		{
			exit(0);
		}
		
		}
	}
	

int main() {
	Vending *vend = new Vending;
	vend->Menu();
	return 0;
}