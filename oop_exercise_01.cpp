
#include <iostream>
#include "oop_exercise_01.h"

using namespace std;

class BritishMoney {
private:
	unsigned long long Pounds;
	unsigned char Shillings;
	unsigned char Pennys;
public:
	BritishMoney(unsigned long long SPounds, unsigned char SShilings, unsigned char SPennys) {
		Pounds = SPounds;
		Shillings = SShilings;
		Pennys = SPennys;
	}

	BritishMoney() {
		Pounds = 0;
		Shillings = 0;
		Pennys = 0;
	}

	unsigned long long getPounds() {
		return this->Pounds;
	}
	char getShillings() {
		return this->Shillings;
	}
	char getPennys() {
		return this->Pennys;
	}
};

void out(BritishMoney tmp) {
	printf("%llu %d %d \n", tmp.getPounds(), tmp.getShillings(), tmp.getPennys());
}

BritishMoney Create() {
	unsigned long long tmp_Pounds = 0;
	unsigned int tmp_Schillings = 0;
	unsigned int tmp_Pennys = 0;
	cin >> tmp_Pounds >> tmp_Schillings >> tmp_Pennys;
	BritishMoney tmp_out = BritishMoney(tmp_Pounds, tmp_Schillings, tmp_Pennys);
	return tmp_out;
}

unsigned long long char_to_ull(unsigned char temp) {
	return static_cast<unsigned long long> (temp);
}

BritishMoney Bringing(unsigned long long tmp) {
	char tmp_Pennys = tmp % 12;
	tmp = tmp  / 12;
	char tmp_Schillings = tmp % 20;
	unsigned long long tmp_Pounds = tmp / 20;
	BritishMoney c = BritishMoney(tmp_Pounds, tmp_Schillings, (int)tmp_Pennys);
	return c;
}

BritishMoney addition(BritishMoney a, BritishMoney b) {
	unsigned long long tmp_Pounds = a.getPounds() + b.getPounds();
	char tmp_Schilling = char_to_ull(a.getShillings()) + char_to_ull(b.getShillings() );
	char tmp_Penny = char_to_ull(a.getPennys()) + char_to_ull(b.getPennys());
	unsigned long long tmp = tmp_Pounds * 240 + char_to_ull(tmp_Schilling) * 12 + char_to_ull(tmp_Penny);
	BritishMoney c = Bringing(tmp);
	return c;
}

BritishMoney Subtraktion(BritishMoney a, BritishMoney b) { 
	unsigned long long tmp_A = a.getPounds() * 240 + char_to_ull(a.getShillings())  * 12 + char_to_ull(a.getPennys());
	unsigned long long tmp_B = b.getPounds() * 240 + char_to_ull(b.getShillings()) * 12 + char_to_ull(b.getPennys());
	unsigned long long tmp_C = tmp_A - tmp_B;
	if (tmp_A >= tmp_B) {
		 tmp_C = tmp_A - tmp_B;
	}
	if (tmp_A < tmp_B) {
		cout << "!Debt received!" << endl;
		tmp_C = tmp_B - tmp_A;
	}
	BritishMoney c = Bringing(tmp_C);
	return c;
}
	
double Division_sum(BritishMoney a, BritishMoney b) {
	unsigned long long tmp_A = a.getPounds() * 240 + char_to_ull(a.getShillings()) * 12 + char_to_ull(a.getPennys());
	unsigned long long tmp_B = b.getPounds() * 240 + char_to_ull(b.getShillings()) * 12 + char_to_ull(b.getPennys());
	double c = 0;
	if (tmp_B != 0) {
		c = (double)tmp_A / tmp_B;
	}
	else {
		cout << "division by zero!!!" << endl;
	}

	return c;
}

BritishMoney FDivision(BritishMoney a, double b) {
	unsigned long long tmp_A = a.getPounds() * 240 + char_to_ull(a.getShillings()) * 12 + char_to_ull(a.getPennys());
	unsigned long long tmp = 0;
	if (b == 0) {
		cout << "division by zero!!!";
		tmp = 0;
	}
	else {
		tmp = round(tmp_A / b);
	}
	
	BritishMoney c = Bringing(tmp);
	return c;
}

BritishMoney Multiply(BritishMoney a, double b) {
	unsigned long long tmp_A = a.getPounds() * 240 + char_to_ull(a.getShillings()) * 12 + char_to_ull(a.getPennys());
	unsigned long long tmp = round(tmp_A * b);
	BritishMoney c = Bringing(tmp);
	return c;
}

bool  equality(BritishMoney a, BritishMoney b) {
	unsigned long long tmp_A = a.getPounds() * 240 + char_to_ull(a.getShillings()) * 12 + char_to_ull(a.getPennys());
	unsigned long long tmp_B = b.getPounds() * 240 + char_to_ull(b.getShillings()) * 12 + char_to_ull(b.getPennys());
	if (tmp_A = tmp_B) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	char input = ' ';
	cout << "For help enter h" << endl;
	cin >> input;
	while (input != 'q') {
		if (input == 'a') {
			BritishMoney a = BritishMoney();
			BritishMoney b = BritishMoney();
			BritishMoney c = BritishMoney();
			cout << "Enter a" << endl;
			a = Create();
			cout << "Enter b" << endl;
			b = Create();
			c = addition(a, b);
			cout << "Your answer is" << endl;
			out(c);
		}
		else if (input == 's') {
			BritishMoney a = BritishMoney();
			BritishMoney b = BritishMoney();
			BritishMoney c = BritishMoney();
			cout << "Enter a" << endl;
			a = Create();
			cout << "Enter b" << endl;
			b = Create();
			c = Subtraktion(a, b);
			cout << "Your answer is" << endl;
			out(c);
		}
		else if (input == 'd') {
			BritishMoney a = BritishMoney();
			BritishMoney b = BritishMoney();
			double c = 0;
			cout << "Enter a" << endl;
			a = Create();
			cout << "Enter b" << endl;
			b = Create();
			c = Division_sum(a, b);
			cout << "Your answer is " << c << endl;
		}
		else if (input == 'g') {
			BritishMoney a = BritishMoney();
			double b = 0;
			BritishMoney c = BritishMoney();
			cout << "Enter a" << endl;
			a = Create();
			cout << "Enter b" << endl;
			cin >> b;
			c = FDivision(a, b);
			cout << "Your answer is" << endl;
			out(c);
		}
		else if (input == 'm') {
			BritishMoney a = BritishMoney();
			double b = 0;
			BritishMoney c = BritishMoney();
			cout << "Enter a" << endl;
			a = Create();
			cout << "Enter b" << endl;
			cin >> b;
			c = Multiply(a, b);
			cout << "Your answer is" << endl;
			out(c);
		}
		else if (input == 'e') {
			BritishMoney a = BritishMoney();
			BritishMoney b = BritishMoney();
			cout << "Enter a" << endl;
			a = Create();
			cout << "Enter b" << endl;
			b = Create();
			if (equality(a, b) == 1) {
				cout << "They are equal";
			}
			else {
				cout << "They are not equal";
			}
		}
		else if (input == 'h') {
			cout << "h - help" << endl << "a - Complex" << endl << "s - Subtraktion" << endl << "d - division by sum" << endl <<	"g - fractional division" << endl <<"m - fractional multiplication" << endl <<"e - comparison" << endl << "q - quit" << endl;

		}
		else {
			cout << "Invalid key, please enter h" << endl;
		}
		cin >> input;
	}
	return 0;
}
