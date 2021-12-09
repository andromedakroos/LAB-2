#include "Header.h"

class alcohol
{
private:

	string alcoName;
	string alcoType;
	int alcoStrength;
	int alcoPrice;
	int alcoCapacity;
public:
	void setName(string alco_name)
	{
		alcoName = alco_name;
	}
	void setType(string alco_type)
	{
		alcoType = alco_type;
	}
	void setStrength(int alco_strength)
	{
		alcoStrength = alco_strength;
	}
	void setPrice(int alco_price)
	{
		alcoPrice = alco_price;
	}
	void setCapacity(int alco_capacity)
	{
		alcoCapacity = alco_capacity;
	}
	string getName()
	{
		return alcoName;
	}
	string getType()
	{
		return alcoType;
	}
	int getStrength()
	{
		return alcoStrength;
	}
	int getPrice()
	{
		return alcoPrice;
	}
	int getCapacity()
	{
		return alcoCapacity;
	}

	void output()
	{
		cout << "�������� �������: " << getName() << "\n��� �������: " << getType() << "\n���-�� ��������: " << getStrength() << "\n����� (��): " << getCapacity() << "\n����(�����): " << getPrice() << "\n" << endl;
	}

	void input()
	{
		string tmp;
		int a;
		cout << "������� �������� �������: " << endl;
		getline(cin, tmp, '\n');
		setName(tmp);
		cout << "���: " << endl;
		getline(cin, tmp, '\n');
		setType(tmp);
		cout << "��������: " << endl;
		cin >> a;
		a = checking(a);
		setStrength(a);
		cout << "�����: " << endl;
		cin >> a;
		a = checking(a);
		setCapacity(a);
		cout << "����: " << endl;
		cin >> a;
		a = checking(a);
		setPrice(a);
		cin.ignore();
	}
	int checking(int a)
	{
		bool success = true;
		while (success)
		{
			if (cin.peek() != '\n' || a <= 0)
			{
				cin.clear();
				cin.ignore(3333333, '\n');
				cout << "������, ��������� ����!" << endl;
				cin >> a;
			}
			else
				success = false;
		}
		return a;

	}
	alcohol()
	{
		alcoName = "����� �������";
		alcoType = "����";
		alcoStrength = 8;
		alcoPrice = 3;
		alcoCapacity = 500;
	}
	alcohol(string n, string t, int s, int p, int c)
	{
		alcoName = n;
		alcoType = t;
		alcoStrength = s;
		alcoPrice = p;
		alcoCapacity = c;
	}
	alcohol(const alcohol & omb)
	{
		alcoName = omb.alcoName;
		alcoType = omb.alcoType;
		alcoStrength = omb.alcoStrength;
		alcoPrice = omb.alcoPrice;
		alcoStrength = omb.alcoStrength;
		alcoCapacity = omb.alcoCapacity;

	}
	/*~alcohol()
	{
		cout << "��������� ���������!" << endl;
	}*/
	friend class newprice;
};

class newprice
{
private:
	int newprice;
public:
	void new_price(int z)
	{
		newprice = z;
	}
	void change(alcohol& brew)
	{
		brew.alcoPrice = newprice;
	}
};
