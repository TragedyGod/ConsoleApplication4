#include"stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

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

	inline void showStorage() const {
		cout << "可乐：" << m_cola->account << endl << "奶茶：" << m_milkT->account << endl;
		cout << "凉茶：" << m_T->account << endl;
	}
	inline void showSoldNum() const {
		cout << m_cola->name << endl << "销售量：" << m_soldCola << endl;
		cout << "销售额：" << m_soldCola*(m_cola->price) << endl;
		cout << m_milkT->name << endl << "销售量：" << m_soldMilkTea << endl;
		cout << "销售额：" << m_soldMilkTea*(m_milkT->price) << endl;
		cout << m_T->name << endl << "销售量：" << m_soldTea << endl;
		cout << "销售额：" << m_soldTea*(m_T->price) << endl;
	}

	void addStore();
	void sellItem();
	void popMenu();

private:
	Drink *m_cola, *m_milkT, *m_T;
	int m_soldCola, m_soldMilkTea, m_soldTea;
};
Drink::Drink(float pr, string n)
	:name(n), price(pr), account(0) {}
Vending::Vending()
	: m_soldCola(0), m_soldMilkTea(0), m_soldTea(0)
{
	m_cola = new Drink(float(2.8), "可乐");
	m_milkT = new Drink(float(3.0), "奶茶");
	m_T = new Drink(float(3.5), "凉茶");
}
void Vending::addStore() {
	cout << "请选择要上架的商品：\n1.可乐\n2.奶茶\n3.凉茶\n";
	int n, count;
	cin >> n;

	if (n > 3) {
		cout << "选择错误" << endl;
		return;
	}

	cout << "请输入要上架的数量：";
	cin >> count;

	if (n == 1)
		m_cola->account += count;
	else if (n == 2)
		m_milkT->account += count;
	else if (n == 3)
		m_T->account += count;
	else {
		cout << "操作失败" << endl;
		return;
	}

	cout << "操作完成" << endl;
}
void Vending::sellItem() {
	cout << "1." << m_cola->name << "：" << endl;
	cout << "价格：" << m_cola->price << ends << "库存：" << m_cola->account << (m_cola->account == 0 ? "（售完）\n" : "\n");
	cout << "2." << m_milkT->name << "：" << endl;
	cout << "价格：" << m_milkT->price << ends << "库存：" << m_milkT->account << (m_milkT->account == 0 ? "（售完）\n" : "\n");
	cout << "3." << m_T->name << "：" << endl;
	cout << "价格：" << m_T->price << ends << "库存：" << m_T->account << (m_T->account == 0 ? "（售完）\n" : "\n");
	cout << "请选择：";
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
			cout << "库存不足" << endl;

		cout << "请输入数量：";
		cin >> num;
	} while (num > acc);

	price *= num;

	float pay = 0;
	do
	{
		if (pay > 0)
			cout << "支付不足" << endl;

		cout << "请支付：";
		cin >> pay;
	} while (pay < price);

	cout << "操作完成" << endl;
	if (pay - price > 0)
		cout << "找零：" << pay - price << endl;

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
void Vending::popMenu() {
	const string menu1 = "========自动贩卖机========\n1.管理人员界面\n2.销售界面\n3.退出\n";
	const string menu2 = "========自动贩卖机========\n1.显示库存\n2.商品上架\n3.销售查询\n";

	int n;
	while (true) {
		cout << menu1 << "请选择：";
		cin >> n;
		if (n == 1) {
			cout << "请输入密码：";
			int password;
			cin >> password;
			if (password != 123) {
				cout << "密码错误" << endl;
				continue;
			}
			cout << menu2 << "请选择：";
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
			default: {
				cout << "选择错误" << endl;
				return;
			}
			}
		}
		else if (n == 2)
			sellItem();
		else if (n == 3)
			exit(0);
	}
}
int main() {
	Vending *vend = new Vending;
	vend->popMenu();
	return 0;
}