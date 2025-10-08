#include <iostream>
int main() {
    int a = 10;        //定义int变量
    int *p = &a;       // p保存的是a的内存地址
    //int *p=a；为什么不行，类型错误，*p是指针，不能赋值变量，只能内存地址
    //int p=&a;同理，也是类型错误，&a取的内存地址，不能赋值给int
    //运算符号&，就是取地址
    std::cout << "a is:" << a << std::endl;      
    std::cout << "p is:" << p << std::endl;       // 输出 p=a的地址
    std::cout << "*p is:" << *p << std::endl;  // 输出 p指向的地址包保存的值，即a的值
    //运算符号*，解引用运算符，获取指针指向的值
    return 0;
}