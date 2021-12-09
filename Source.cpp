#include "Header.h"
#include "class.cpp"

int main()
{
	string tmp;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*alcohol ohota;
	ohota.output();*/
	/*alcohol param("Коронет", "Пиво", 4, 3, 568);
	param.output();
	alcohol copy(param);
	copy.output();*/
	int choice, i, z;
	vector<alcohol>brew;
	alcohol temp;
	newprice cost;
	do
	{

		cout << "Для добавления напитка введите - 1" << endl;
		cout << "Для просмотра напитков введите - 2" << endl;
		cout << "Для удаления напитка введите - 3" << endl;
		cout << "Для изменения свойств напитка введите - 4" << endl;
		cout << "Для изменения стоимости напитка введите - 5" << endl;
		cout << "Для сортировки по крепости напитков введите - 6" << endl;
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			system("CLS");
			brew.push_back(alcohol());
			brew[brew.size() - 1].input();
			break;
		case 2:
			system("CLS");
			if (brew.size() == 0)
			{
				cout << "Напитков в баре пока нет, но можете добавить\n";
			}
			else
				for (i = 0; i < brew.size(); i++)
				{
					brew[i].output();
				}
			break;
		case 3:
			system("CLS");
			cout << "Введите название напитка, который хотите удалить: ";
			getline(cin, tmp, '\n');
			for (i = 0; i < brew.size(); i++)
			{
				if (brew[i].getName() == tmp)
				{
					brew.erase(brew.begin() + i);
					cout << "Элемент успешно удален!" << endl;
				}
				else
					cout << "Такого напитка в баре нет, но можем добавить" << endl;
			}
		case 4:
			system("CLS");
			cout << "Введите название напитка, который хотите изменить: ";
			getline(cin, tmp, '\n');
			for (i = 0; i < brew.size(); i++)
			{
				if (brew[i].getName() == tmp)
				{
					brew[i].input();
					cout << "Элемент успешно изменен!" << endl;
					break;
				}
				else
					cout << "Такого напитка в баре нет, но можем добавить" << endl;
			}
		case 5:
			system("CLS");
			cout << "Введите название напитка, стоимость хотите изменить: ";
			getline(cin, tmp, '\n');
			for (i = 0; i < brew.size(); i++)
			{
				if (brew[i].getName() == tmp)
				{
					cout << "Введите новую стоимость напитка" << endl;
					cin >> z;
					cost.new_price(z);
					cost.change(brew[i]);
					break;
				}
				else
					cout << "Такого напитка в баре нет, но можем добавить" << endl;
			}
		case 6:
			system("CLS");
			cout << "Выполнена сортировка по возрастанию крепости напитков: " << endl;
			for (int i = 0; i < brew.size() - 1; i++)
			{
				for (int j = 0; j < brew.size() - i - 1; j++)
				{
					if (brew[j].getPrice() > brew[j + 1].getPrice())
					{
						temp = brew[j];
						brew[j] = brew[j + 1];
						brew[j + 1] = temp;
					}
				}
			}
			for (i = 0; i < brew.size(); i++)
			{
				brew[i].output();
			}
			break;
		}

	} while (choice != 8);

	return 0;
}