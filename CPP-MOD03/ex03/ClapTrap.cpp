#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap")
{
    hit_points = 10;
    energy_points = 10;
    attack_damage = 10;
	cout << "ClapTrap Default Constructor called" << endl;
}

ClapTrap::ClapTrap(std::string name) {
    this->name = name;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
	cout << "ClapTrap Constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy) {
	cout << "ClapTrap Copy constructor called" << endl;
	*this = cpy;
}

ClapTrap::~ClapTrap() {
	cout << "ClapTrap Destructor called" << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy) {
	this->name = cpy.name;
	this->attack_damage = cpy.attack_damage;
	this->energy_points = cpy.energy_points;
	this->hit_points = cpy.hit_points;
	return (*this);
}

void ClapTrap::attack(const std::string &target) {
	if (this->energy_points > 0 && this->hit_points > 0) {
		cout << "ClapTrap " << this->name << " attacking " << target << " causing " << this->attack_damage
			 << " points of damage!" << endl;
		this->energy_points--;
	}else
		cout << "Not enough energy points or ClapTrap is dead!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hit_points > 0) {
        cout << "ClapTrap " << this->name << " taking damage (" << amount << ") ";
        if (this->hit_points < amount)
            amount = this->hit_points;
        this->hit_points -= amount;
        cout << "(After taking damage the new HP is " << this->hit_points << ")." << endl;
    }else
        cout << this->name << " is dead!";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy_points > 0 && this->hit_points > 0) {
        cout << "ClapTrap " << this->name << " repairing it self (+" << amount << ") "  << "(!This will cause an energy point!)" << endl;
        this->hit_points += amount;
        this->energy_points--;
    }else
        cout << "Can not repair!"<< endl;
}
