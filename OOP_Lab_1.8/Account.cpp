#include "Account.h"
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <iomanip>
#include <math.h>
using namespace std;

void Account::setSecondname(string value)
{
	secondname = value;
}

bool Account::setNo(int value)
{
	if (value > 0)
	{
		no = value;
		return true;
	}
	else
	{
		no = 0;
		return false;
	}
}

bool Account::setPercent(double value)
{
	if (value > 0)
	{
		percent = value;
		return true;
	}
	else
	{
		percent = -value;
		return false;
	}
}

void Account::setSumma()
{
	summa.Read();
}

bool Account::Init(int no, double percent)
{
	return setNo(no) && setPercent(percent);
}

string Account::Read(string prizvysche) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������ ������� ��������: "; cin >> prizvysche;
	return prizvysche;
}

int Account::Read(int nomer) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������ ����� ����������� �������: "; cin >> nomer;
	return nomer;
}

void Account::Display()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << toString();
}

string Account::toString() const
{

	stringstream sout;
	sout << "----------------------------------------------------------------------------\n";
	sout << "|500h|200h|100h| 50h| 20h| 10h|  5h|  2h|  1h| 50c| 25c| 10c|  5c|  2c|  1c|\n";
	sout << "----------------------------------------------------------------------------\n";
	sout << "|" << setw(4) << summa.getH500() << "|" << setw(4) << summa.getH200() << "|" << setw(4) << summa.getH100() << "|" <<
		setw(4) << summa.getH50() << "|" << setw(4) << summa.getH20() << "|" << setw(4) << summa.getH10() << "|" << setw(4) <<
		summa.getH5() << "|" << setw(4) << summa.getH2() << "|" << setw(4) << summa.getH1() << "|" << setw(4) << summa.getC50() <<
		"|" << setw(4) << summa.getC25() << "|" << setw(4) << summa.getC10() << "|" << setw(4) << summa.getC5() << "|" <<
		setw(4) << summa.getC2() << "|" << setw(4) << summa.getC1() << "|\n" <<
		"----------------------------------------------------------------------------\n";

	int a = summa.getH500() * 500 + summa.getH200() * 200 + summa.getH100() * 100 +
		summa.getH50() * 50 + summa.getH20() * 20 + summa.getH10() * 10 + summa.getH5() * 5 + summa.getH2() * 2 + summa.getH1();
	int b = summa.getC50() * 50 + summa.getC25() * 25 + summa.getC10() * 10 + summa.getC5() * 5 + summa.getC2() * 2 + summa.getC1();
	while (b >= 100)
	{
		b -= 100;
		a += 1;
	}
	if (b < 10)
		sout << "Sum = " << a << ",0" << b << endl;
	else
		sout << "Sum = " << a << "," << b << endl;

	return sout.str();
}

void Account::ChangeOwner()
{
	string prizvysche;
	int nomer = 0;
	setSecondname(Read(prizvysche));
	setNo(Read(nomer));
	summa.Read();
	setPercent(5);
}

void Account::GetMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "������ ������ �� ������ �����?" << endl;
		cout << "[1] - 500 ���." << endl;
		cout << "[2] - 200 ���" << endl;
		cout << "[3] - 100 ���" << endl;
		cout << "[4] - 50 ���" << endl;
		cout << "[5] - 20 ���" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa.setH500(summa.getH500() - 1);
			cout << "�� ������ ����� 500 �������" << endl;
			break;
		case 2:
			summa.setH200(summa.getH200() - 1);
			cout << "�� ������ ����� 200 �������" << endl;
			break;
		case 3:
			summa.setH100(summa.getH100() - 1);
			cout << "�� ������ ����� 100 �������" << endl;
			break;
		case 4:
			summa.setH50(summa.getH50() - 1);
			cout << "�� ������ ����� 50 �������" << endl;
			break;
		case 5:
			summa.setH20(summa.getH20() - 1);
			cout << "�� ������ ����� 20 �������" << endl;
		}
		break;
		cout << endl;
	} while (no != 6);
}

void Account::AddMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "������ ������ �� ������ �������� �� �������?" << endl;
		cout << "[1] - 500 ���." << endl;
		cout << "[2] - 200 ���" << endl;
		cout << "[3] - 100 ���" << endl;
		cout << "[4] - 50 ���" << endl;
		cout << "[5] - 20 ���" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa.setH500(summa.getH500() + 1);
			cout << "�� ������ ������� 500 �������" << endl;
			break;
		case 2:
			summa.setH200(summa.getH200() + 1);
			cout << "�� ������ ������� 200 �������" << endl;
			break;
		case 3:
			summa.setH100(summa.getH100() + 1);
			cout << "�� ������ ������� 100 �������" << endl;
			break;
		case 4:
			summa.setH50(summa.getH50() + 1);
			cout << "�� ������ ������� 50 �������" << endl;
			break;
		case 5:
			summa.setH20(summa.getH20() + 1);
			cout << "�� ������ ������� 20 �������" << endl;
		}
		break;
		cout << endl;
	} while (no != 6);
}

void Account::MakePercent()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	sum = summa.Total();
	int no;
	do {
		cout << "�� ������ ������ ���������� " << percent << "% �� ��� ������?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * (percent / 100);
			cout << "�� ������ ���������� �������!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin);
}

void Account::ToDollar()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int no;
	do {
		cout << "�� ������ ������ ��������� " << summa.Total() << "���. � �������?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * 0.033;
			cout << "�� ������ �������� ����� � �������!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin);
}

void Account::ToEuro()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int no;
	do {
		cout << "�� ������ ������ ��������� " << summa.Total() << "���. � ����?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * 0.030;
			cout << "�� ������ �������� ����� � ����!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin);
}

void Account::Propys()
{
	double x = summa.Total();
	double frac = 0;
	double integral = 0;
	frac = modf(x, &integral);
	int numb = (int)integral;

	int osn[11] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

	string basis[11][10] = {
		{"","","","","","","","","",""},
		{"","����","���","���","������","�'���","�����","��","���","������"},
		{"","������","��������","��������","�����","�'�������","���������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","�����","������","���'�����"},
		{"","����","��","���","������","�'���","�����","��","���","���'���"},
		{"","������","��������","��������","�����","�'�������","���������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","������","������","���'�����"},
		{"","����","���","���","������","�'���","�����","��","���","���'���"},
		{"","������","��������","��������","�����","�'�������","����������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","�����","������","���'�����"},
		{"","����","���","��� ","������","�'���","�����","��","���","���'���"} };


	string termination[10][10] = {
		{"","","","�����","","","�������","","","�������"},
		{"","","","������","","","������","","","������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"} };

	string dec[10] = { "������","����������","����������","����������","������������","�'���������","�����������","���������","����������","���'���������" };
	string result;

	if (!numb) {
		result = "���� ";
	}
	int n1 = numb;
	int cnt = 0;

	//��������� ������� ������� � ����
	while (numb) {
		numb /= 10;
		cnt++;
	}
	int cile = 0;

	while (n1) {
		if (!((cnt + 1) % 3)) {
			if ((n1 / osn[cnt]) == 1) {
				n1 %= osn[cnt];
				--cnt;
				cile = n1 / osn[cnt];
				n1 %= osn[cnt];
				result += dec[cile];
				--cnt;
				if (!(cnt % 3))
					result += " " + termination[0][cnt] + " ";
			}
			if (!cnt) break;
		}
		cile = n1 / osn[cnt];
		n1 %= osn[cnt];
		result += basis[cnt][cile] + " ";
		--cnt;
		if (!(cnt % 3))
			result += termination[cile][cnt] + " ";
	}
	cout << "�� ������ ������� " << result << "������� " << fixed << setprecision(0) << frac * 100 << " ������";
	cout << endl;
}
Account Account::Add(const Account x, const Account y)
{
	Account c;
	c.summa.setH500(x.summa.getH500() + y.summa.getH500());
	c.summa.setH200(x.summa.getH200() + y.summa.getH200());
	c.summa.setH100(x.summa.getH100() + y.summa.getH100());
	c.summa.setH50(x.summa.getH50() + y.summa.getH50());
	c.summa.setH20(x.summa.getH20() + y.summa.getH20());
	c.summa.setH10(x.summa.getH10() + y.summa.getH10());
	c.summa.setH5(x.summa.getH5() + y.summa.getH5());
	c.summa.setH2(x.summa.getH2() + y.summa.getH2());
	c.summa.setH1(x.summa.getH1() + y.summa.getH1());
	c.summa.setC50(x.summa.getC50() + y.summa.getC50());
	c.summa.setC25(x.summa.getC25() + y.summa.getC25());
	c.summa.setC10(x.summa.getC10() + y.summa.getC10());
	c.summa.setC5(x.summa.getC5() + y.summa.getC5());
	c.summa.setC2(x.summa.getC2() + y.summa.getC2());
	c.summa.setC1(x.summa.getC1() + y.summa.getC1());

	return c;
}

Account Account::Subtract(const Account x, const Account y)
{
	double subt = x.summa.getH500() * 500. + x.summa.getH200() * 200. + x.summa.getH100() * 100. + x.summa.getH50() * 50. +
		x.summa.getH20() * 20. + x.summa.getH10() * 10. + x.summa.getH5() * 5. + x.summa.getH2() * 2. + x.summa.getH1() + x.summa.getC50() * 0.5 +
		x.summa.getC25() * 0.25 + x.summa.getC10() * 0.1 + x.summa.getC5() * 0.05 + x.summa.getC2() * 0.02 + x.summa.getC1() * 0.01 -
		(y.summa.getH500() * 500. + y.summa.getH200() * 200. + y.summa.getH100() * 100. + y.summa.getH50() * 50. +
			y.summa.getH20() * 20. + y.summa.getH10() * 10. + y.summa.getH5() * 5. + y.summa.getH2() * 2. + y.summa.getH1() + y.summa.getC50() * 0.5 +
			y.summa.getC25() * 0.25 + y.summa.getC10() * 0.10 + y.summa.getC5() * 0.05 + y.summa.getC2() * 0.02 + y.summa.getC1() * 0.01);
	if (subt <= 0)
	{
		cerr << "Sum on first account is lesser than that on the latter.\n";
	}
	else
	{
		int hrn = (int)subt;
		int coin = (floor((subt - hrn) * 100 + 0.501));

		return Change(hrn, coin);
	}
}

Account Account::Multiply(const double y)
{
	Account c;
	if (y <= 0)
		summa.Init(c.summa.getH500(), c.summa.getH200(), c.summa.getH100(), c.summa.getH50(), c.summa.getH20(), c.summa.getH10(), c.summa.getH5(), c.summa.getH2(), c.summa.getH1(), c.summa.getC50(),
			c.summa.getC25(), c.summa.getC10(), c.summa.getC5(), c.summa.getC2(), c.summa.getC1());
	else
	{
		if (y != 1)
		{
			double sum = summa.getH500() * 500. + summa.getH200() * 200. + summa.getH100() * 100. + summa.getH50() * 50. +
				summa.getH20() * 20. + summa.getH10() * 10. + summa.getH5() * 5. + summa.getH2() * 2. + summa.getH1() + summa.getC50() * 0.5 +
				summa.getC25() * 0.25 + summa.getC10() * 0.1 + summa.getC5() * 0.05 + summa.getC2() * 0.02 + summa.getC1() * 0.01;
			sum *= y;
			int hrn = (int)sum;
			int coin = (floor((sum - hrn) * 100 + 0.501));

			return Change(hrn, coin);
		}
		else
			summa.Init(c.summa.getH500(), c.summa.getH200(), c.summa.getH100(), c.summa.getH50(), c.summa.getH20(), c.summa.getH10(), c.summa.getH5(), c.summa.getH2(), c.summa.getH1(), c.summa.getC50(),
				c.summa.getC25(), c.summa.getC10(), c.summa.getC5(), c.summa.getC2(), c.summa.getC1());
	}
	return c;
}

Account Account::Division(const double y)
{
	Account c;
	if (y == 0)
		summa.Init(c.summa.getH500(), c.summa.getH200(), c.summa.getH100(), c.summa.getH50(), c.summa.getH20(), c.summa.getH10(), c.summa.getH5(), c.summa.getH2(), c.summa.getH1(), c.summa.getC50(),
			c.summa.getC25(), c.summa.getC10(), c.summa.getC5(), c.summa.getC2(), c.summa.getC1());
	else
	{
		if (y != 1)
		{
			double sum = summa.getH500() * 500. + summa.getH200() * 200. + summa.getH100() * 100. + summa.getH50() * 50. +
				summa.getH20() * 20. + summa.getH10() * 10. + summa.getH5() * 5. + summa.getH2() * 2. + summa.getH1() + summa.getC50() * 0.5 +
				summa.getC25() * 0.25 + summa.getC10() * 0.1 + summa.getC5() * 0.05 + summa.getC2() * 0.02 + summa.getC1() * 0.01;
			sum = sum / y;
			int hrn = (int)sum;
			int coin = (floor((sum - hrn) * 100 + 0.501));

			return Change(hrn, coin);
		}
		else
			summa.Init(c.summa.getH500(), c.summa.getH200(), c.summa.getH100(), c.summa.getH50(), c.summa.getH20(), c.summa.getH10(), c.summa.getH5(), c.summa.getH2(), c.summa.getH1(), c.summa.getC50(),
				c.summa.getC25(), c.summa.getC10(), c.summa.getC5(), c.summa.getC2(), c.summa.getC1());
	}
	return c;
}

Account Account::DivOfSums(const Account x, const Account y) {
	double subt = (x.summa.getH500() * 500. + x.summa.getH200() * 200. + x.summa.getH100() * 100. + x.summa.getH50() * 50. +
		x.summa.getH20() * 20. + x.summa.getH10() * 10. + x.summa.getH5() * 5. + x.summa.getH2() * 2. + x.summa.getH1() + x.summa.getC50() * 0.5 +
		x.summa.getC25() * 0.25 + x.summa.getC10() * 0.1 + x.summa.getC5() * 0.05 + x.summa.getC2() * 0.02 + x.summa.getC1() * 0.01) /
		(y.summa.getH500() * 500. + y.summa.getH200() * 200. + y.summa.getH100() * 100. + y.summa.getH50() * 50. +
			y.summa.getH20() * 20. + y.summa.getH10() * 10. + y.summa.getH5() * 5. + y.summa.getH2() * 2. + y.summa.getH1() + y.summa.getC50() * 0.5 +
			y.summa.getC25() * 0.25 + y.summa.getC10() * 0.10 + y.summa.getC5() * 0.05 + y.summa.getC2() * 0.02 + y.summa.getC1() * 0.01);
	int hrn = (int)subt;
	int coin = (floor((subt - hrn) * 100 + 0.501));

	return Change(hrn, coin);
}

Account Account::Change(int hrn, int coin)
{
	Account d;
	int hh500 = hrn / 500;
	hrn -= hh500 * 500;
	int hh200 = hrn / 200;
	hrn -= hh200 * 200;
	int hh100 = hrn / 100;
	hrn -= hh100 * 100;
	int hh50 = hrn / 50;
	hrn -= hh50 * 50;
	int hh20 = hrn / 20;
	hrn -= hh20 * 20;
	int hh10 = hrn / 10;
	hrn -= hh10 * 10;
	int hh5 = hrn / 5;
	hrn -= hh5 * 5;
	int hh2 = hrn / 2;
	hrn -= hh2 * 2;
	int cc50 = coin / 50;
	coin -= cc50 * 50;
	int cc25 = coin / 25;
	coin -= cc25 * 25;
	int cc10 = coin / 10;
	coin -= cc10 * 10;
	int cc5 = coin / 5;
	coin -= cc5 * 5;
	int cc2 = coin / 2;
	coin -= cc2 * 2;
	summa.Init(hh500, hh200, hh100, hh50, hh20, hh10, hh5, hh2, hrn, cc50, cc25, cc10, cc5, cc2, coin);

	return d;
}

bool Less(Account a, Account b) {
	return a.summa.Total() < b.summa.Total();
}
bool NLess(Account a, Account b) { return !Less(a, b); }

bool Great(Account a, Account b) {
	return a.summa.Total() > b.summa.Total();
}
bool NGreat(Account a, Account b) { return !Great(a, b); }

bool Equal(Account a, Account b) {
	return a.summa.Total() == b.summa.Total();
}
bool NEqual(Account a, Account b) { return !Equal(a, b); }

void Account::Money::setH500(const int x) { h500 = x; };
void Account::Money::setH200(const int x) { h200 = x; };
void Account::Money::setH100(const int x) { h100 = x; };
void Account::Money::setH50(const int x) { h50 = x; };
void Account::Money::setH20(const int x) { h20 = x; };
void Account::Money::setH10(const int x) { h10 = x; };
void Account::Money::setH5(const int x) { h5 = x; };
void Account::Money::setH2(const int x) { h2 = x; };
void Account::Money::setH1(const int x) { h1 = x; };
void Account::Money::setC50(const int x) { c50 = x; };
void Account::Money::setC25(const int x) { c25 = x; };
void Account::Money::setC10(const int x) { c10 = x; };
void Account::Money::setC5(const int x) { c5 = x; };
void Account::Money::setC2(const int x) { c2 = x; };
void Account::Money::setC1(const int x) { c1 = x; };

void Account::Money::Init(int hh500, int hh200, int hh100, int hh50,
	int hh20, int hh10, int hh5, int hh2, int hh1,
	int cc50, int cc25, int cc10, int cc5, int cc2, int cc1)
{
	hh500 > 0 ? h500 = hh500 : h500 = 0;
	hh200 > 0 ? h200 = hh200 : h200 = 0;
	hh100 > 0 ? h100 = hh100 : h100 = 0;
	hh50 > 0 ? h50 = hh50 : h50 = 0;
	hh20 > 0 ? h20 = hh20 : h20 = 0;
	hh10 > 0 ? h10 = hh10 : h10 = 0;
	hh5 > 0 ? h5 = hh5 : h5 = 0;
	hh2 > 0 ? h2 = hh2 : h2 = 0;
	hh1 > 0 ? h1 = hh1 : h1 = 0;
	cc50 > 0 ? c50 = cc50 : c50 = 0;
	cc25 > 0 ? c25 = cc25 : c25 = 0;
	cc10 > 0 ? c10 = cc10 : c10 = 0;
	cc5 > 0 ? c5 = cc5 : c5 = 0;
	cc2 > 0 ? c2 = cc2 : c2 = 0;
	cc1 > 0 ? c1 = cc1 : c1 = 0;
}

void Account::Money::Read()
{
	int hh500, hh200, hh100, hh50, hh20, hh10, hh5, hh2, hh1, cc50, cc25, cc10, cc5, cc2, cc1;
	cout << "������ ������� ����� ������:" << endl;
	cout << "500 = "; cin >> hh500;
	cout << "200 = "; cin >> hh200;
	cout << "100 = "; cin >> hh100;
	cout << "50 = "; cin >> hh50;
	cout << "20 = "; cin >> hh20;
	cout << "10 = "; cin >> hh10;
	cout << "5 = "; cin >> hh5;
	cout << "2 = "; cin >> hh2;
	cout << "1 = "; cin >> hh1;
	cout << "0.50 = "; cin >> cc50;
	cout << "0.25 = "; cin >> cc25;
	cout << "0.10 = "; cin >> cc10;
	cout << "0.5 = "; cin >> cc5;
	cout << "0.02 = "; cin >> cc2;
	cout << "0.01 = "; cin >> cc1;
	Init(hh500, hh200, hh100, hh50, hh20, hh10, hh5, hh2, hh1, cc50, cc25, cc10, cc5, cc2, cc1);
}

double Account::Money::Total() {
	int hrn, kop;
	double sum;
	hrn = h500 * 500 + h200 * 200 + h100 * 100 +
		h50 * 50 + h20 * 20 + h10 * 10 + h5 * 5 + h2 * 2 + h1;
	kop = c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5 + c2 * 2 + c1;
	sum = (double)hrn + (double)kop / 100.;
	return sum;
}

string Account::Money::toString() const
{
	stringstream sout;
	int a = h500 * 500 + h200 * 200 + h100 * 100 +
		h50 * 50 + h20 * 20 + h10 * 10 + h5 * 5 + h2 * 2 + h1;
	int b = c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5 + c2 * 2 + c1;
	while (b >= 100)
	{
		b -= 100;
		a += 1;
	}
	if (b < 10)
		sout << "C��� = " << a << ",0" << b << endl;
	else
		sout << "���� = " << a << "," << b << endl;

	return sout.str();
}

void Account::Money::Display() const
{
	cout << toString();
}