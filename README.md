This is an NCURSES-like library that allows modern terminals to support 24-bit color, mouse support, non-blocking IO and so forth which will allow you to do cool stuff in text mode.

Doing non-blocking I/O is easy, here's how you do it:
```C++
set_raw_mode(true); //Turns on non-blocking I/O
int ch = quick_read(); //Reads a character without waiting for a newline to be hit
```

You might notice that it returns an int, not a char. That's because it has to be able to return non-ASCII codes, like for arrow keys, function keys, and so forth, as well as "ERR", which means that no keystroke was read at all (and so is going to be what you get 99% of the time).

Here's how you can parse the result of quick_read():
```C++
if (ch == ERR) //Nothing was read
    ;
else if (ch == RIGHT_ARROW) { //It can read arrow keys, etc., which are impossible to get with cin
    x++;
}
else if (ch == LEFT_ARROW) {
    x--;
}
else if (ch == DOWN_ARROW) {
    y++;
else if (ch == UP_ARROW) {
    y--;
}
else if (ch == HOME) { //It can read keys like HOME, DEL, END, PAGE_UP, PAGE_DOWN...
}
```

Check out the quick_read.cc demo file to see more examples of quick_read in action. You can use this to make text-based video games games like Snake, Tetris, and so forth without the game pausing every time it tries to read from the keyboard. You can also have it read mouse clicks and mousewheel events. 

If you want to do colors with this header file, well, there's a simple way with a few preset colors, and a slightly more complicated way that lets you control the foreground and background colors in 24-bit color mode.

The Simple Way uses enums to pick from sixteen preset colors in your terminal:
```C++
std::cout << RED << "Hello World!\n"; //Will print Hello World in bright red (and all future text will be in bright red)
std::cout << BOLDBLUE << "Hello " << BOLDYELLOW << "World!" << RESET << std::endl; //Will print Hello in a bold blue color, World in a bold yellow, and then reset the text colors back to normal for future text
```

![image](https://user-images.githubusercontent.com/8254997/123490297-9e3e7180-d5c8-11eb-863e-3fa37bbf4660.png)

The Medium Way allows you to specify explicit 8-bit values for the red, green, and blue values for both the foreground and background color:
```C++
setbgcolor(80,80,40); //Set background color to some ugly brown
setcolor(180,0,0); //Set foreground color to 75% red
std::cout << "Hello World" << RESET << std::endl;
```

![image](https://user-images.githubusercontent.com/8254997/123490322-aac2ca00-d5c8-11eb-97a7-442be809c03f.png)

You can also use this to do artwork, make gradients, and so forth, like this:
```C++
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        setbgcolor(0,i*10+15*j,i*20);
        std::cout << " ";
    }
    resetcolor();
    std::cout << '\n';
}
```

Which makes this:

![image](https://user-images.githubusercontent.com/8254997/123490484-f8d7cd80-d5c8-11eb-9ffd-47e4fceed238.png)


If you set your font size small enough, you can actually render images inside of a text terminal - this is actually a screenshot from PuTTY:
![image](https://user-images.githubusercontent.com/8254997/123489896-d42f2600-d5c7-11eb-8a81-c0989abe0224.png)

PuTTY will tend to lag or crash when rendering 4K images inside of it. I reported this as a bug to the developers but haven't heard back from them yet. 😝

Oh, and then one other really useful function is the ability to get the size of the terminal. If you have C++17, you can even get both the columns and rows in one line like this:
```C++
    const auto [ROWS,COLS] = get_terminal_size();
```
