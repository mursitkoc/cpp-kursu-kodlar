#include <iostream>

struct Nec {
public:
	Nec(int val) : mx(val) {}
	[[nodiscard]] bool operator==(const Nec& other)const
	{
		return mx == other.mx;
	}
private:
	int mx;
};


int main()
{
	std::cout << std::boolalpha;
	Nec n1{ 43 }, n2{ 76 };

	std::cout << (n1 == n2) << '\n';
	std::cout << (n1 != n2) << '\n';
	std::cout << (10 != n1) << '\n';
	std::cout << (76 != n2) << '\n';
}