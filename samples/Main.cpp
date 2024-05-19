#include <iostream>

#include "Polynomial.h"

int main() {
	std::cout << "Commands:" << std::endl;
	std::cout << "1 (Enter polynom)" << std::endl;
	std::cout << "2 (Print polynom)" << std::endl;
	std::cout << "3 (Add polynoms)" << std::endl;
	std::cout << "4 (Subtract polynoms)" << std::endl;
	std::cout << "5 (Mult polynom by number)" << std::endl;
	std::cout << "6 (Mult polynoms)" << std::endl;
	std::cout << "7 (Differentiate polynom)" << std::endl;
	std::cout << "8 (Integrate polynom)" << std::endl;
	std::cout << "9 (Calculate polynom in point)" << std::endl;
	std::cout << "10 (Exit)" << std::endl;

	size_t command = 0;
	Polynomial polynom1, polynom2;

	while (command != 10) {
		command = 0;
		while ((command < 1) || (command > 10)) {
			std::cout << std::endl << "Your command: ";
			std::cin >> command;
		}
		std::cout << std::endl;

		if (command == 1) {
			command = 0;
			std::string str = "";
			while ((command < 1) || (command > 2)) {
				std::cout << "Which polynom you want to enter? 1 or 2: ";
				std::cin >> command;
			}
			std::cout << "You should enter polynom as follows: 1.0x1y2z3+2.0x2y1z0+-3.0x3y2z1" << std::endl;
			std::cout << "Enter your polynom: ";
			std::cin >> str;
			if (command == 1)
				polynom1.ParsePolynom(str);
			if (command == 2)
				polynom2.ParsePolynom(str);
			continue;
		}

		if (command == 2) {
			command = 0;
			while ((command < 1) || (command > 2)) {
				std::cout << "Which polynom you want to print? 1 or 2: ";
				std::cin >> command;
			}
			if (command == 1)
				std::cout << polynom1.PolynomToString() << std::endl;
			if (command == 2)
				std::cout << polynom2.PolynomToString() << std::endl;
			continue;
		}

		if (command == 3) {
			std::cout << (polynom1 + polynom2).PolynomToString() << std::endl;
			continue;
		}

		if (command == 4) {
			std::cout << (polynom1 - polynom2).PolynomToString() << std::endl;
			continue;
		}

		if (command == 5) {
			command = 0;
			double k = 1.0;
			while ((command < 1) || (command > 2)) {
				std::cout << "Which polynom you want to mult? 1 or 2: ";
				std::cin >> command;
			}
			std::cout << "Enter double number: ";
			std::cin >> k;
			if (command == 1)
				std::cout << (polynom1 * k).PolynomToString() << std::endl;
			if (command == 2)
				std::cout << (polynom2 * k).PolynomToString() << std::endl;
			continue;
		}

		if (command == 6) {
			std::cout << (polynom1 * polynom2).PolynomToString() << std::endl;
			continue;
		}

		if (command == 7) {
			command = 0;
			char charCommand = ' ';
			while ((command < 1) || (command > 2)) {
				std::cout << "Which polynom you want to differentiate? 1 or 2: ";
				std::cin >> command;
			}
			while ((charCommand != 'x') && (charCommand != 'y') && (charCommand != 'z')) {
				std::cout << "Differentiation variable? x, y or z: ";
				std::cin >> charCommand;
			}
			if (command == 1)
				std::cout << polynom1.Differentiate(charCommand).PolynomToString() << std::endl;
			if (command == 2)
				std::cout << polynom2.Differentiate(charCommand).PolynomToString() << std::endl;
			continue;
		}

		if (command == 8) {
			command = 0;
			char charCommand = ' ';
			while ((command < 1) || (command > 2)) {
				std::cout << "Which polynom you want to integrate? 1 or 2: ";
				std::cin >> command;
			}
			while ((charCommand != 'x') && (charCommand != 'y') && (charCommand != 'z')) {
				std::cout << "Integration variable? x, y or z: ";
				std::cin >> charCommand;
			}
			if (command == 1)
				std::cout << polynom1.Integrate(charCommand).PolynomToString() << std::endl;
			if (command == 2)
				std::cout << polynom2.Integrate(charCommand).PolynomToString() << std::endl;
			continue;
		}

		if (command == 9) {
			while ((command < 1) || (command > 2)) {
				std::cout << "Which polynom you want to calculate? 1 or 2: ";
				std::cin >> command;
			}
			double x = DBL_MAX, y = DBL_MAX, z = DBL_MAX;
			while ((x == DBL_MAX) || (y == DBL_MAX) || (z == DBL_MAX)) {
				std::cout << "Enter x double value: ";
				std::cin >> x;
				std::cout << "Enter y double value: ";
				std::cin >> y;
				std::cout << "Enter z double value: ";
				std::cin >> z;
			}
			if (command == 1)
				std::cout << polynom1.CalculateInPoint(x, y, z) << std::endl;
			if (command == 2)
				std::cout << polynom2.CalculateInPoint(x, y, z) << std::endl;
			continue;
		}
	}
	std::cout << "EXIT";
	return 0;
}