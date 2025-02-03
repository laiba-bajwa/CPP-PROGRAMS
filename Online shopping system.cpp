#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string>

using namespace std;

class mall
{
	public:
		void intro() const
		{
			cout << setw(50) << "Group 1 Mall" << endl;
			cout << setw(60) << "Welcome to our online mall" << endl;
		}
};

class manu: public mall
{
	public:
		int choice()
		{
			int enter;
			cout << "From which category you want to buy press that index:" << endl;
			cout << "1. Men Cloth" << endl;
			cout << "2. Women Cloth" << endl;
			cout << "3. Grocery" << endl;
			cout << "4. Watches" << endl;
			cout << "5. Perfumes" << endl;
			cout << "6. Shoes" << endl;
			cin >> enter;
			return enter;
		}
};

class product_list: public mall
{	
	public:
		int t;
		int pro_list(int a)
		{
			ifstream file;
			string line;
			switch(a)
			{
				case 1:
					file.open("men_cloth.txt");
					break;
				case 2:
					file.open("women_cloth.txt");
					break;
				case 3:
					file.open("grocery.txt");
					break;
				case 4:
					file.open("watches.txt");
					break;
				case 5:
					file.open("perfumes.txt");
					break;
				case 6:
					file.open("shoes.txt");
					break;
				default:
					cout << "Error" << endl;
					return -1;
			}
			if(file.is_open())
			{
				cout << "Choose from the following products by selecting the index of the product you are interested in:" << endl;
				while(getline(file, line))
				{
					cout << line << endl;
				}
				file.close();
				cin >> t;
				return t;
			}
			else
			{
				cout << "Unable to open file" << endl;
				return -1;
			}
		}
};

class pro_details: public mall
{
	public:
		char details_yn(int l)
		{
			ifstream file;
			string line;
			char ch;
			switch(l)
			{
				case 1:
					file.open("product_details_1.txt");
					break;
				case 2:
					file.open("product_details_2.txt");
					break;
				case 3:
					file.open("product_details_3.txt");
					break;
				default:
					cout << "Error you entered wrong thing." << endl;
					return 'n';
			}
			if(file.is_open())
			{
				cout << "Details of the product: " << endl;
				while(getline(file, line))
				{
					cout << line << endl;
				}
				file.close();
				cout << "Want to purchase it? Press y for yes and n for no." << endl;
				ch = _getche();
				return ch;
			}
			else
			{
				cout << "Unable to open file" << endl;
				return 'n';
			}
		}
};

class pay_details: public mall
{
	public:
		int details(char op)
		{
			int th;
			if(op == 'y')
			{
				cout << "\nChoose payment method: " << endl
					 << "1. Debit card" << endl
					 << "2. Easypaisa" << endl
					 << "3. Jazzcash" << endl
					 << "4. Cash on delivery" << endl;
				cin >> th;
				return th;
			}
			else if(op == 'n')
			{
				cout << "Thanks for visiting." << endl;
				return -1;
			}
			else
			{
				cout << "Invalid input" << endl;
				return -1;
			}
		}
};

class payment: public mall
{
	public:
		void final_details(int z)
		{
			ofstream file;
			int no;
			if(z == 1)
			{
				cout << "Enter your credit card details: ";
				cin >> no;
				file.open("payment_details.txt");
				if(file.is_open())
				{
					file << "Payment Method: Credit Card" << endl;
					file << "Card Number: " << no << endl;
					file.close();
				}
			}
			else if(z == 2)
			{
				cout << "Enter your Easypaisa number: ";
				cin >> no;
				file.open("payment_details.txt");
				if(file.is_open())
				{
					file << "Payment Method: Easypaisa" << endl;
					file << "Easypaisa Number: " << no << endl;
					file.close();
				}
			}
			else if(z == 3)
			{
				cout << "Enter your Jazzcash number: ";
				cin >> no;
				file.open("payment_details.txt");
				if(file.is_open())
				{
					file << "Payment Method: Jazzcash" << endl;
					file << "Jazzcash Number: " << no << endl;
					file.close();
				}
			}
			else if(z == 4)
			{
				cout << "Will be delivered to you soon." << endl;
				file.open("payment_details.txt");
				if(file.is_open())
				{
					file << "Payment Method: Cash on Delivery" << endl;
					file.close();
				}
			}
			else
			{
				cout << "Invalid payment method." << endl;
			}
		}
};

int main()
{
	char cha;
	int c, j, po;
	manu m;
	m.intro();
	c = m.choice();
	product_list p;
	j = p.pro_list(c);
	if(j != -1)
	{
		pro_details u;
		cha = u.details_yn(j);
		if(cha == 'y' || cha == 'n')
		{
			pay_details fg;
			po = fg.details(cha);
			if(po != -1)
			{
				payment bg;
				bg.final_details(po);
			}
		}
	}
	return 0;
}
