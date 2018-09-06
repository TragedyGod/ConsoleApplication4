#pragma once
//声明和定义自动售卖机（Vending）类
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
	m_cola = new Drink(float(2.8), "可乐");
	m_milkT = new Drink(float(3.0), "奶茶");
	m_T = new Drink(float(3.5), "凉茶");
}
//管理员操作:补充库存
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
//1存入金额  2选择商品 3支付和找零 4当库存不足时报错  5当支付金额不足时报错
void Vending::sellItem() {
	
}
//菜单函数（管理人员界面\销售界面\退出）
//管理人员界面：显示库存\商品上架\销售查询
//密码默认123
void Vending::Menu() {

}



//定义商品的结构体变量包括商品的名称、数量、价格。
struct Drink {
	Drink(float pr, string n);
	string name;
	float price;
	int account;
};









