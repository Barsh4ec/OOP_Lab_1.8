#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include "Account.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Account a, b, c, d;
	a.setSecondname("��������");
	a.setNo(1);
	a.setPercent(6.4);
	a.setSumma();
	int no;
	do {
		a.Display();
		cout << "������� �������:" << fixed << setprecision(2) << a.getSecondame() << endl;
		cout << "������� ��" << endl;
		cout << "[1] - ������ �������� �������" << endl;
		cout << "[2] - ����� ����� ���� ������ � �������" << endl;
		cout << "[3] - �������� ����� �� �������" << endl;
		cout << "[4] - ���������� �������" << endl;
		cout << "[5] - ��������� ���� � ������" << endl;
		cout << "[6] - ��������� ���� � ����" << endl;
		cout << "[7] - �������� ���� ��������" << endl;
		cout << "[8] - ��������� ���" << endl;
		cout << "[9] - �������� ���" << endl;
		cout << "[10] - ������ ���" << endl;
		cout << "[11] - ������ ���� �� ������� �����" << endl;
		cout << "[12] - �������� �� ������� �����" << endl;
		cout << "[13] - �������� ���������" << endl;
		cout << "[0] - ��������� ���������" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		{
		case 1:
			a.ChangeOwner();
			break;
		case 2:
			a.GetMoney();
			break;
		case 3:
			a.AddMoney();
			break;
		case 4:
			a.MakePercent();
			break;
		case 5:
			a.ToDollar();
			break;
		case 6:
			a.ToEuro();
			break;
		case 7:
			a.Propys();
			break;
		case 8:
			b.setSumma();
			b.Display();
			c = c.Add(a, b);
			cout << "�������: " << endl;
			c.Display();
			break;
		case 9:
			b.setSumma();
			b.Display();
			d.Subtract(a, b);
			cout << "�������: " << endl;
			d.Display();
			break;
		case 10:
			b.setSumma();
			b.Display();
			a.DivOfSums(a, b);
			cout << "�������: " << endl;;
			a.Display();
			break;
		case 11:
			double x;
			cout << "�� ��� ����� ���� �� ���� �������? : "; cin >> x;
			a.Division(x);
			cout << "�������: " << endl;
			a.Display();
			break;
		case 12:
			cout << "�� ��� ����� ���� �� ���� ���������? : "; cin >> x;
			a.Multiply(x);
			cout << "�������: " << endl;
			a.Display();
			break;
		case 13:
			b.setSumma();
			b.Display();
			if (Less(a, b) == true)
				cout << "����� ���� ����� �� �����" << endl;
			if (NLess(a, b) == true)
				cout << "����� ���� ����� �� �����" << endl;
			if (Great(a, b) == true)
				cout << "����� ���� ����� �� �����" << endl;
			if (NGreat(a, b) == true)
				cout << "����� ���� ����� �� �����" << endl;
			if (Equal(a, b) == true)
				cout << "����� � ����� ���� ����" << endl;
			if (NEqual(a, b) == true)
				cout << "����� � ����� ���� �� ����" << endl;
			break;
		}
		cout << endl;
	} while (no != 0);

	return 0;
}