#include <iostream>
#include <clocale> 
using namespace std;
class dynamarr
{
private:
	int *din_arr;
	int size;
public:
	dynamarr()
	{
		size = 0;
		din_arr = new int[0];
	}
	dynamarr(int n) : size(n)
	{
		din_arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			din_arr[i] = i;
		}
	}
	dynamarr(const dynamarr &mass)// ����������� ������ �������
	{
		din_arr = new int[mass.size];
		size = mass.size;
		for (int i = 0; i < mass.size; i++)
		{
			din_arr[i] = mass.din_arr[i];
		}
	}
	dynamarr& operator=(const dynamarr &mass)//�������� ������������
	{
		if (this != &mass)
		{
			delete[] din_arr;
			din_arr = new int[mass.size];
			for (int i = 0; i < mass.size; i++)
			{
				din_arr[i] = mass.din_arr[i];
			}
			size = mass.size;
		}
		return *this;
	}
	void changel(int index, int number)
	{
		din_arr[number] = index;
	}
	int getelement(int number)
	{
		return din_arr[number];
	}
	int minEl()
	{
		int min = din_arr[0];
		for (int i = 0; i < (size - 1); i++)
		{
			if (din_arr[i + 1] < min)
			{
				min = din_arr[i + 1];
			}
		}
		return min;
	}
	bool SortCheck()//�������� �� ��������������� ��������� � �������;
	{
		int i;
		bool Check = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (din_arr[i] > din_arr[i + 1])
			{
				return Check;
			}
		}
		if (i == size - 1)
		{
			Check = 1;
			return Check;
		}
	}
	dynamarr Subarr(int size, int arraysize) // �������� ���������� � ��������� ����������
	{
		int i, j = 0, m = 0;
		dynamarr subarr(size);
		double n;
		for (i = 0; i < arraysize; i++)
		{
			n = i % 2;
			if (n != 0)
			{
				m = din_arr[i];
				subarr.changel(m, j);
				j++;
			}
		}
		return subarr;
	}
	void Print(int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << " " << i << " ������� - " << din_arr[i] << endl;
		}
	}
	~dynamarr()
	{
		delete[] din_arr;
	}
};
int main(void)
{
	setlocale(0, "");
	int n, v;
	int elements;
	int num;
	int type = 0;
	cout << "������� ������ �������: " << endl;
	cin >> n;
	dynamarr mass(n);
	do
	{
		cout << "��� �� ������ �������:/n 1-������ ������� ������� �� ��� �������.(��������� ������� � 0)\n 2-������ ������� �� ������� 3-������ ����������� �������./n 4-���������, �������� �� ������ �������������./n 5- �������� ��������� � ��������� �������." << endl;
		cin >> v;
		while ((v < 1) || (v > 5))
		{
			cout << "��� �� ������ �������:/n 1-������ ������� ������� �� ��� �������.(��������� ������� � 0)\n 2-������ ������� �� ������� 3-������ ����������� �������./n 4-���������, �������� �� ������ �������������./n 5- �������� ��������� � ��������� �������." << endl;
			cin >> v;
		}
		switch (v)
		{
		case 1:
			cout << "������� ������ ��������, ������� ������ ��������:" << endl;
			cin >> num;
			cout << "������� ����� �������:\n" << num << " �������: ";
			cin >> elements;
			mass.changel(elements, num);
			break;
		case 2:
			cout << "������� ������:\n";
			cin >> num;
			cout << "\n������� ��� ������� " << num << " - ���  " << mass.getelement(num);
			break;
		case 3:
			cout << "����������� �������: " << mass.minEl() << endl;
			break;
		case 4:
			if (mass.SortCheck() == 1)
				cout << "����������." << endl;
			else
				cout << "�� ����������." << endl;
			break;
		case 5:
			dynamarr mas;
			mas = mass;
			int nsize = floor(n / 2);
			mas = mas.Subarr(nsize, n);
			cout << "��������� ��������� :" << endl;
			mas.Print(nsize);
			break;
		}
		cout << " ������ ��������� ������?/n1-��,0-���" << endl;
		cin >> type;
		while ((type != 0) && (type != 1))
		{
			cout << ("�������  0 ��� 1.\n");
			cin >> type;
		}
	} while (type == 0);
	system("pause");
	return 0;
}