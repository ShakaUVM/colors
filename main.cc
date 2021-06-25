#include "colors.h"

int main() {
	//Simple way of using the code - use enums:
	//Will print Hello World in bright red (and all future text will be in bright red)
	std::cout << RED << "Hello World!\n"; 
	//Will print Hello in a bold blue color, World in a bold yellow, and then reset the text colors back to normal for future text
	std::cout << BOLDBLUE << "Hello" << BOLDYELLOW << " World!" << RESET << std::endl; 

	//Medium difficulty way of using the code - specify 24-bit colors:
	setbgcolor(80,80,40); //Set background color to some ugly brown
	setcolor(180,0,0); //Set foreground color to 75% red
	std::cout << "Hello World" << RESET << std::endl;

	//You can also use this library to make images and artwork
	//Here is a simple 24-bit color gradient:
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			setbgcolor(0,i*10+15*j,i*20);
			std::cout << " ";
		}
		resetcolor();
		std::cout << '\n';
	}

	//High difficulty - see quickread.cc
}
