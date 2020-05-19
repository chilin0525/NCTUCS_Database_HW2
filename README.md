## How to Check Memory Leak

1. you should download valgrind first

2. ` g++ -std=c++17 -O3 -g -o hw2 main.cpp utils.cpp index.cpp`
(where `-g` is different in makefile! be careful!)

3. `valgrind --leak-check=full --show-leak-kinds=all --verbose ./hw2`

then we have detailed messages about memery leak in our code.

4. if you see `All heap blocks were freed -- no leaks are possible` that ok!

![](https://i.imgur.com/dn1xFHw.png)
