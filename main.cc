#include "colors.h"

int main() {
	//Basic Hello World
	std::cout << "Hello World" << std::endl;
	//Print Hello in red
	std::cout << RED << "Hello " << RESET << "World" << std::endl;
	setbgcolor(80,80,40); //Set background color to some ugly brown
	setcolor(180,0,0); //Set foreground color to 75% red
	std::cout << "Hello World" << RESET << std::endl;
	//Print gradient
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			setbgcolor(0,i*10+15*j,i*20);
			std::cout << " ";
		}
		resetcolor();
		std::cout << '\n';
	}
}
