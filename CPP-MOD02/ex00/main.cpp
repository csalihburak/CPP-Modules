#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	b = c;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}