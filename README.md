This is an NCURSES-like library that allows modern terminals to support 24-bit color, mouse support, non-blocking IO and so forth which will allow you to do cool stuff in text mode.

There's a simple way of using it, a medium difficulty way of using it, and an advanced way of using it.

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


If you set your font size small enough, you can actually render images inside of a text terminal - this is a screenshot from PuTTY:
![image](https://user-images.githubusercontent.com/8254997/123489896-d42f2600-d5c7-11eb-8a81-c0989abe0224.png)

Another thing that C++ has needed for a long time is the ability to do nonblocking I/O on the keyboard. For example, you want to see if an arrow key is held down without causing the whole program to pause and wait on input (as cin does by default). Check out the quick_read.cc demo file to see how that works. You can use this to make text-based video games games like Snake, Tetris, and so forth without the game pausing every time it tries to read from the keyboard.
