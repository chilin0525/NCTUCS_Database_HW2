## How to Check Memory Leak

1. you should download valgrind first

2. ` g++ -std=c++17 -O3 -g -o hw2 main.cpp utils.cpp index.cpp`
(where `-g` is different in makefile! be careful!)

3. `valgrind --leak-check=full --show-leak-kinds=all --verbose ./hw2` (會顯示詳細錯誤訊息的)
(`valgrind --tool=memcheck ./hw2` 助教提供的，不會有詳細錯誤訊息)
then we have detailed messages about memery leak in our code.

4. if you see `All heap blocks were freed -- no leaks are possible` that ok!

![](https://i.imgur.com/dn1xFHw.png)

* 防呆一下: 最近看到有人在看, 在這裡提醒一下去年這份作業被我寫爆炸了, 學弟妹們別亂抄... 會爆炸的呦^^ 
