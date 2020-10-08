#include "/public/colors.h"
#include <cstdlib>
#include <csignal>

void bailout() {
	set_mouse_mode(false);
	set_raw_mode(false);
	//clearscreen();
}
void interrupt_handler(int x) {
	std::exit(0);
}

void mousedown_handler(int row, int col) {
	std::cout << "Mouse down. Row: " << row << " Col: " << col << std::endl;
}

void mouseup_handler(int row, int col) {
	std::cout << "Mouse up. Row: " << row << " Col: " << col << std::endl;
}

//Demo Main showing the different functions in colors.h
int main()
{
	//These two lines prevent us from leaving the terminal in a bad state if we ctrl-c out or exit()
	atexit(bailout); //Callback when we quit, call bailout to clean up the terminal
	signal(SIGINT,interrupt_handler);

	//See how large the terminal is in both dimensions
	const auto [ROWS,COLS] = get_terminal_size();

	set_raw_mode(true); //Enable non-blocking IO & quick_read
	std::cout << "Your terminal has: " << ROWS << " rows and " << COLS << " cols.\n";
	std::cout << "Two player Tron-like game. One person clicks to move, the other uses the arrow keys.\n";
	std::cout << "Hit space to continue\n";
	while (quick_read() != ' ') usleep(10'000);
	std::cout << ''; //Clear screen

	set_cursor_mode(false); //Disable drawing the cursor
	set_mouse_mode(true); //Enable mouse events
	//Set up callbacks for mouse events
	on_mousedown(mousedown_handler); //This function will be called whenever a mousedown takes place
	on_mouseup([](int,int){}); //Disable mouseup event (not needed, mouseup is disabled by default)

	int p1_pos_x = 0, p1_pos_y = 0;
	int p1_vel_x = 0, p1_vel_y = 0;
	int p2_pos_x = 0, p2_pos_y = 0;
	int p2_vel_x = 0, p2_vel_y = 0;
	while (true) {
		int c = quick_read();
		if (c == 'q') break;
		if (c == ERR) usleep(10'000);
		else std::cout << c << std::endl;
	}
}
