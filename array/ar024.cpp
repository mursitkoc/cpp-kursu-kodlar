#include <ostream>

template<typename T, size_t size>
std::ostream&
operator<<(std::ostream& os, const std::array<T, size>& ar)
{
	os << "[";
	size_t i;
	for (i = 0; i < size - 1; ++i)
		os << ar[i] << ", ";
	return os << ar[i] << "]";
}

#include <array>
#include <iostream>

int main()
{
	using namespace std;

	array<array<int, 5>, 2> ax{12, 4, 7, 8, 13, 1, 7, 9, 2, 6};
	cout << ax << "\n";
}
