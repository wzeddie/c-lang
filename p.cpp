#include <iostream>
int main() {
    int x = 10;  //定义一个变量
    int *p = &x;       // 定义一个指向整数的指针变量 p，指向 x 的地址
    std::cout << "x 的值为：" << x << std::endl;       // 输出 x 的值
    std::cout << "p 的值为：" << p << std::endl;       // 输出 p 的值，即 x 的地址
    std::cout << "*p 指向的值为：" << *p << std::endl;  // 输出 p 指向的值，即 x 的值
    return 0;
}
