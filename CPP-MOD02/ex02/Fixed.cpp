#include "Fixed.hpp"

Fixed::Fixed() {
    fixed_point_nbr = 0;
}

Fixed::Fixed(const Fixed &cpy) {
    *this = cpy;
}

Fixed::Fixed(const int nbr) {
    fixed_point_nbr = (nbr << fractional_bits);
}

Fixed::Fixed(const float nbr) {
    fixed_point_nbr = (int)roundf((nbr * fixed_point));
}
Fixed::~Fixed(){}

Fixed &Fixed::operator=(const Fixed &to_cpy){
    this->fixed_point_nbr = to_cpy.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &to_out) {
    os << to_out.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &gr) const {
	return (this->fixed_point_nbr > gr.fixed_point_nbr);
}

bool Fixed::operator<(const Fixed &ls) const {
	return (this->fixed_point_nbr < ls.fixed_point_nbr);
}

bool Fixed::operator>=(const Fixed &greq) const {
	return (this->fixed_point_nbr >= greq.fixed_point_nbr);
}

bool Fixed::operator<=(const Fixed &lseq) const {
	return (this->fixed_point_nbr <= lseq.fixed_point_nbr);
}

bool Fixed::operator!=(const Fixed &noteq) const {
	return (this->fixed_point_nbr != noteq.fixed_point_nbr);
}

bool Fixed::operator==(const Fixed &eq) const {
	return (this->fixed_point_nbr == eq.fixed_point_nbr);
}

Fixed Fixed::operator+(const Fixed &to) const {
	Fixed buff(this->toFloat() + to.toFloat());
	return (buff);
}
Fixed Fixed::operator-(const Fixed &to) const {
	Fixed buff(this->toFloat() - to.toFloat());
	return (buff);
}

Fixed Fixed::operator*(const Fixed &to) const {
	Fixed buff(this->toFloat() * to.toFloat());
	return (buff);
}

Fixed Fixed::operator/(const Fixed &to) const {
	Fixed buff(this->toFloat() / to.toFloat());
	return (buff);
}

//pre
Fixed &Fixed::operator++() {
	this->fixed_point_nbr++;
	return (*this);

}

Fixed &Fixed::operator--() {
	this->fixed_point_nbr++;
	return (*this);
}
// post
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->fixed_point_nbr++;
	return (temp);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->fixed_point_nbr++;
	return (temp);
}

//Member Functions

const Fixed &Fixed::min(const Fixed &x, const Fixed &y) {
	if (x < y)
		return x;
	return y;
}

Fixed &Fixed::max(Fixed &x, Fixed &y) {
	if (x > y)
		return x;
	return y;
}

Fixed &Fixed::min(Fixed &x, Fixed &y) {
	if (x < y)
		return x;
	return y;
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y) {
	if (x > y)
		return x;
	return y;
}

int Fixed::toInt() const {
    return ((fixed_point_nbr) >> fractional_bits);
}

float Fixed::toFloat() const {
    return (((float)(fixed_point_nbr)) / fixed_point);
}

int Fixed::getRawBits() const {
    return (this->fixed_point_nbr);
}

void Fixed::setRawBits(const int raw) {
    this->fixed_point_nbr = raw;
}