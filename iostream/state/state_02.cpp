#include <iostream>

int main()
{
	using namespace std;

	int x{};

	cout << "bir sayi giriniz: ";
	cout << boolalpha;
	cin >> x;

	cout << "eof : " << cin.eof() << "\n";
	cout << "fail : " << cin.fail() << "\n";
	cout << "bad : " << cin.bad() << "\n";

	cout << "girdiginiz sayi = " << x << "\n";
}
