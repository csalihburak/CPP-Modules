#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Weapon
{
	private:
		string type;
	public:
		Weapon(string tp);
		const string	&getType(void);
		void			setType(string tp);
};

#endif