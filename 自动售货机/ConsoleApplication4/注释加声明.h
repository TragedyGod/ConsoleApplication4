#pragma once
//�����Ͷ����Զ���������Vending����
class Vending {
public:
	Vending();

	inline void showStorage() const {
		cout << "���֣�" << m_cola->account << endl << "�̲裺" << m_milkT->account << endl;
		cout << "���裺" << m_T->account << endl;
	}
	inline void showSoldNum() const {
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
//����Ա����:������
void Vending::addStore() {
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
//1������  2ѡ����Ʒ 3֧�������� 4����治��ʱ����  5��֧������ʱ����
void Vending::sellItem() {
	
}
//�˵�������������Ա����\���۽���\�˳���
//������Ա���棺��ʾ���\��Ʒ�ϼ�\���۲�ѯ
//����Ĭ��123
void Vending::Menu() {

}



//������Ʒ�Ľṹ�����������Ʒ�����ơ��������۸�
struct Drink {
	Drink(float pr, string n);
	string name;
	float price;
	int account;
};









