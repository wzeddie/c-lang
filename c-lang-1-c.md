# 目标和主要内容
1.C 和 C++ 的共同部分：基础数据类型 + 输入输出 + 指针（内存地址） + 数组 + 函数。  

2.过渡到C++：
- 字符串，把 char[] + <string.h> 转换为 string  
- 内存管理，把 malloc/free 分配/释放内存转换为 new/delete和vector （自动管理内存）  
- 输入输出，把 scanf/printf 转换为 cin/cout  
- 学习 STL（标准数据类型库）的容器（vector、map、set）   
`vector` 就是会自动长大的数组。  对应python，就是list（列表）
`map` 就是插入时会自动排序的「键:值字典」。  对应python，参考dict（哈希表）
`set` 就是插入时会自动去重并排序的「集合」。  对应python，参考dict
- 学习 <algorithm> 提供的排序、二分等.写好了排序、二分查找、合并、洗牌、最大/小值等几十种经典算法，直接调用就行。#include <algorithm>
- 了解类、继承、多态，但 NOI 实际编程题 几乎不考 OOP，所以只需入门，但是类在实际软件开发中是必学的，用的最多。
## 动态语言和静态语言
c与c++为静态类型语言，所有每个变量、函数、方法等都要提前定义`好数据类型`
```
比如python，动态语言x不用提前定义数据类型
x = 42        # Python 自动推断 int
x = "hello"   # 再换成 str 也行
但静态语言不行
x= 42;        // ❌ error: unknown type name 'x'
int x = 42;   // 正确
x = "hello";  // ❌ 编译错误：incompatible types when assigning to type ‘int’ from type ‘char *’ 
```
## 基础数据类型
一个字节，8bit，11111111，16进=FF，10进制=255   
基础整数int型
```c
short int a; //2字节，赋值范围 −2¹⁵ ~  2¹⁵，简写 short a
int a;     //4字节，赋值范围-2³¹ ~ 2³¹-1
long int a; //简写long a，32位操作系统4字节，64位8字节
long long int a;//8字节， 赋值范围-2⁶³ ~ 2⁶³-1 ，简写 long long a,优先
为什么这么多，因为历史原因，早起的电脑内存容量都很小，要节省空间，避免浪费
```
浮点数double型
```c
float num; //4字节，保留有效数字6-7位，有效数字从左边第一个非零数字开始一直数到最后一位，多出来的不保存
double num; //8字节，保留有效数字15-16位，优先
double d = 12345678901234567890.0;   // 20 位数字，实际只保留：12345678901234560000.0
long double num //16个字节，保留20位左右。
特别注意 ，c语言在数值类型中，整型超出范围溢出、浮点误差问题。
```
unsigned 用于数字的符号控制，只能赋值非负数
```c
unsigned int num //取值范围就是0到2³¹-1，其他同理
```
一维数组和二维数组
```c
    // 方法1: 完全初始化
    int arr[5] = {1, 2, 3, 4, 5};   
    // 方法2: 部分初始化，未初始化的元素自动为0
    int arr[5] = {1, 2}; // {1, 2, 0, 0, 0}    
    // 方法3: 不指定长度，编译器自动计算
    int arr[] = {1, 2, 3, 4, 5}; // 长度为5
    int arr[10];       //定义一个包含10个整型元素的数组

要求：
类型必须相同（不能混合 int/char/double）
内存连续，因此能用内存地址+1，快速访问。

    //二维数组，常用于表格、棋盘问题、邻接矩阵问题
    int a[3][4];  
// 方法1: 完全初始化
    int matrix1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };   
    //这种二维数组是不允许创建，除非指定为matrix1[][3]
     int matrix1[][] = {
        {1, 2, 3},
        {4, 5, 6}
    };  
-------------------
//对比python语法
matrix = [
    [1, 'a', 3, 'hello'],
    ['#', 6, 7.5, True],
    [None, 10, '中', '12']
]
//python本质采用list的对象
//格式不同点，[]和{}
//变量名不用带维度[][]
//C的数组类型，行列固定，不能随意pop和append，除非用C++的容器类型
//数字和字符可以混用
```

C元的布尔类型bool，还要提前导入库<stdbool.h>，已经被C++的布尔代替免导入，直接用

```c
bool flag = true;
bool flag = false;//小写字母
```
常量类型const
```C
const double PI = 3.14;
```

c语言的单字符char、字符串char[]，以及相关的拷贝、拼接等方法，均被C++的string代替了,直接学C++的语法就可以了
```c++
//c语言淘汰部分
char s='a'; //单个字节，只能赋值单个字符，且只用单引号。
char s[]="ab"; //多字节，字符串用双引号。

//C++下string
#include <string>        // 1. 必须包含
using std::string;       // string是命名空间里面的，需要引入std命名空间
string s1;               // 空串
string s2 = "hello";     // 赋值
string s1= s2;      // 拷贝构造
s1[0] = 'A';     // 直接下标修改字符
string s3 = s1 + ", " + s2;  //拼接
s1.substr(0, 3);   // 截取子串 [0,3)，取0,1,2位置
s1.append("!!!"); //原地追加
s1.insert(2, "ABC");  // 在位置2插入
s1 == s2 //比较
if (s1 < s2) { }    // 字典序比较=按字符对应的asii编码进行逐个比较
索引  0 1 2 3 4 5 6
s1:   a p p l e
s2:   a p r i c o t
第 0 列：'a' == 'a' → 继续
第 1 列：'p' == 'p' → 继续
第 2 列：'p' vs 'r' → ASCII 'p'=112 < 'r'=114
因此就得出 s1 小于 s2，后面字符不再看。
//具体使用场景，比较后，可以按字母排序。
s1.replace(0, 5, "hi"); // 替换，先删除0、1、2、3、4，这个字符，同时用hi代替，
s1.find("h")//查找,返回的是下标
s1.size()//长度，s.length()

//一维字符串数组和二维字符串数组
#include <string>
using std::string;
    string s1[] = {"d", "c", "java", "cpp"};
    string s2[3][2] = {
        {"apple",  "banana"},
        {"orange", "grape"},
        {"pear",   "peach"}
    };
在 C++ 开发中几乎不用 char[] 管字符串，全部改用 std::string。
```
强制类型转换和字符编码
```c

//强制转换为整数类型。
char b='a'；//b 里存的是字母a的ASCII 97 二进制 01100001
int a=int(b) //输出为97数字
//强制转换字符型
int a=1；//a是数字1
string b = to_string(a);//b是字符的'1'

//ASCII 码（American Standard Code for Information Interchange）
//是最早、最基础的**字符编码表**，把常见英文字母、数字、符号、控制符分别映射到 0–200 的整数，差不多占用空间1个字节，0-255
//随着计算机的普及，原来的1个字节编码不够用，需要扩充，中文，有繁体没办法输出
//GB2312 2字节，支持对应6763个常见汉字，大陆早期国标
//BIG5 2个字节，繁体中文，港澳台早期主流
//目前主流GBK 或者UTF-8	，扩充占用4个字节，现在主流的编码，只能支持2万多汉字
//操作演示中文乱码情况，win系统下启动cmd，手动修改编码 chcp 437（ascii编码），然后写入中文到文档echo 你好 > test.txt，打开文件默认就是乱码

          GB2312（占2个字节）         ASCII（1字节）              
a      00000000  01100001                 01100001
中     11010110  11010000                    /

顺便提下，在计算机领域除了字符编码外，还有常见的
字符编码：文字映射到字节上，ASCII、UTF-8、GBK
图片编码：像素映射到字节上，jpg，png、gif、bmp
视频编码：视频帧映射到字节，H.264/AVC（mp4）、H.265/HEVC、AV1
音频编码：PCM波形（声压）映射到字节，AAC、MP3、Opus
图片，视频，音频，会涉及到很多压缩技术，既要能省空间，又要清晰，所以里面有信息论（熵），线性代数（矩阵）工具，用于研究失真优化。
``` 

指针类型=内存地址，这是c和c++，特有的。
常见指针类型：
  
普通指针：指向某种类型的变量。   
空指针 (NULL)：表示不指向任何地址。   
指针数组 / 数组指针：存放多个地址。   
函数指针：存放函数入口地址。   
基本指针具体写法：     
int *p; // double *q; // char *s;   
int *p1 = NULL;   
int *p = arr;  //数组名称
void (*fp1)() = hello; //函数名称 


```c++
#include <iostream>
int main() {
    int a = 10;        //定义int变量
    int *p = &a;       // p保存的是a的内存地址
    //int *p=a；为什么不行，类型错误，*p是指针，不能赋值变量，只能内存地址
    //int p=&a;同理，也是类型错误，&a取的内存地址，不能赋值给int
    //运算符号&，就是取地址
    std::cout << "a is" << a << std::endl;      
    std::cout << "p is" << p << std::endl;       // 输出 p=a的地址
    std::cout << "*p is" << *p << std::endl;  // 输出 p指向的地址包保存的值，即a的值
    //运算符号*，解引用运算符，获取指针指向的值
    return 0;
}
//输出结果，p为
a is:10
p is:0x4ef73ffce4（十六进制）
*p is:10
```
指针+数组的演示
```c++
int arr[3] = {10, 20, 30};
int *p = arr;        // arr是数组类型，数组名默认为首元素地址，所以可以赋值
//利用指针来循环遍历数组
for (int i = 0; i < 3; ++i)
    printf("%d ", *(p + i));   // *p+i循环输出数组中各个元素。
    //i=0时，*p指针指向首位
    //i=1时，*p指针下移，指向次位
    ......

字符串数组
std::string arr[3] = {"hello", "world", "c++"}; // string 数组
std::string *p = arr;                         // 指针指向首元素
for (int i = 0; i < 3; ++i){
    std::cout << *(p + i) << ' ';//同理
}


```
函数指针,就是用来存放函数入口地址的变量
定义函数指针：返回值类型 (*指针名)(参数类型,...)
```c
#include <iostream>
using namespace std;

void hello() {
    cout << "Hello, World!" << endl;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    // 定义函数指针：返回值类型 (*指针名)(参数类型,...)
    void (*fp1)() = hello;//格式与原函数一一对应
    int (*fp2)(int, int) = add;//格式与原函数一一对应

    // 使用函数指针调用函数
    fp1();  // 调用 hello()
    cout << fp2(3, 5) << endl;  // 调用 add(3,5)，输出 8
}
小结
指针 = “直接操内存的钥匙”
大部分上层的应用软件，STL 容器、算法看不见指针使用。指针也可以支持，
链表节点、二叉树节点、图邻接表都要“指向下一节点”——指针就是连接纽带
但是，在实际使用中越接近计算机底层，系统的内核，指针依旧是最直接、最通用、零开销的工具：
Linux read(int fd, void *buf, size_t n) //传递指针类型，直接读取磁盘数据到缓冲区
Windows WriteFile(HANDLE, void *buf, …)//同理，win系统句柄调用


```


scanf/printf输入输出（了解），后被C++的cin/cout输出输入代替
```c++
//printf 输出
printf("age is:", age);//直接这样写无法输出age
//引入占位符%，才能把age传给这个占位符
printf("age is：%d \n", age);
//什么是占位符
在字符串中里先占个座，告诉 printf/scanf：等会儿把我换成对应实参
//有哪些占位符
int  double  字符串   指针类型
%d    %f      %s     %p
//顺序要一一对应
printf("年龄=%d 身高=%f 姓名=%s\n", age, height, name); 
//如何显示中文，避免乱码
注意：在终端要提前配置好中文，否则会乱码。
powershell和vscode的终端中运行以下命令
chcp 65001
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8

//scanf输入
int  age;
double height;
char name[20];
//传递的是地址，因为要读取用户输入内容，然后写到具体地址里面
scanf("%d %f %s", &age, &height, name); // age、height 必须 &；name 不用
//name为什么不用&符号？
//name是数组类型，数组的名称默认就数组地址，而且是首元素的地址。
```
C++的cin/cout输出输入
```c
//cin / cout 来自头文件 <iostream>
//不用scanf/printf格式字符串，也不用取地址符号
//名称来源cout=c out 输出；cin=c  in 输入的意思。
#include <iostream>   // 包含 cin、cout
using namespace std;  // 省去 std:: 前缀（可写全 std::cin）

int main() {
    int age;
    double height;
    string name;

    cout << "请输入年龄、身高、姓名：";   // 把后面的文字传给cout，让cout输出,
    cin >> age >> height >> name;        // 把用户的输入，连续写入到age、height、name中,cin >> 会自动按空格、换行分隔输入。

    cout << "年龄=" << age << '\n'
         << "身高=" << height << '\n'
         << "姓名=" << name << endl;     // endl 换行并刷新缓冲区= '\n'
    return 0;
}
\\读取整行
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);  // 读取一整行
    cout << line << endl;
}
```
函数，函数是一段封装了特定功能的代码块，可以被重复使用
如何定义:返回类型 函数名(参数列表) { 函数体 }
```c++

// C 或 C++ 的函数示例
int add(int a, int b) {   // 返回类型 int，函数名 add，形参 a,b
    return a + b;         // 函数体
}
//调用
int result = add(3, 5);   // 调用 add 函数，result = 8
//函数分类

有返回值函数：如 int add(int x, int y)。
无返回值函数：用 void，如 void printHello()。
带参数/无参数函数：如 int f()、int g(int n)
带默认参数： int f(int a,int b=2)

//与python区别
//没有def
//函数体、参数，均没有定义数据类型
//没有{}
def add(a, b):
    return a + b

//仅限于C++支持的函数重载
提前写好多个同名函数：
必须在参数列表上有所区别
参数 类型不同
参数 个数不同
参数 顺序不同
在c语言中，要写成这样：
int addInt(int a, int b);
double addDouble(double a, double b);
long addLong(long a, long b);
但是在c++中，可以直接写成同名：
int add(int a, int b);
double add(double a, double b);
long add(long a, long b);
//代码演示
#include <iostream>
using namespace std;

int power(int x) {
    return x * x;
}

int power(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) result =result*x;
    return result;
}

int main() {
    cout << power(5) << endl;      // 调用一个参数 → 25
    cout << power(2, 3) << endl;   // 调用两个参数 → 8
    return 0;
}
//比如 abs(int)、abs(double)、abs(long)，标准库本身就有很多利用函数重载版本。

//函数的返回空类型
void foo(void);   // 无参、无返回值
```
变量作用域：局部变量和全局变量
静态变量：静态局部变量和静态全局变量
```c++
//变量的作用域
局部变量	写在函数或者代码块{}里面，包括写在main函数里面也是
全局变量 写在函数以外，程序顶部的为全局变量。
#include <stdio.h>
int global_var = 100; // 全局变量，定义在所有函数之外
void myFunction() {
    int local_in_func = 20; // 局部变量，只在 myFunction 内有效
    printf("Inside function: %d\n", local_in_func);
    global_var++; // 可以修改

}
int main() {
    int local_in_main = 10; // 局部变量，只在 main 函数内有效
    printf("Inside main: %d\n", local_in_main);
    // printf("%d\n", local_in_func); // 错误！无法访问其他函数内的局部变量
    myFunction();
    return 0;
}


//静态变量static
1、静态局部变量
#include <iostream>
using namespace std;
void normalCounter() {
    int count = 0;  // 普通局部变量
    count++;
    cout << "普通计数: " << count << endl;
}
void staticCounter() {
    static int count = 0;  // 静态局部变量
    count++;
    cout << "静态计数: " << count << endl;
}
int main() {
    cout << "普通局部变量：" << endl;
    normalCounter();  // 输出：普通计数: 1
    normalCounter();  // 输出：普通计数: 1
    normalCounter();  // 输出：普通计数: 1
    
    cout << "静态局部变量：" << endl;
    staticCounter();  // 输出：静态计数: 1
    staticCounter();  // 输出：静态计数: 2
    staticCounter();  // 输出：静态计数: 3
    return 0;
}
关键点：
static int count = 0; 静态局部变量只执行一次（在第一次调用函数时）普通局部变量是每次都会执行
静态局部之后每次调用函数，变量都保持上一次的值
静态局部变量在程序结束时才被销毁
2、静态全局变量和extern外部声明
静态全局变量只能在本文件中使用，其他文件不能通过extern来访问
// file1.cpp
#include <iostream>
using namespace std;

// 定义变量
static int fileLocalVar = 100;  // 静态全局变量，只在当前文件可用
int globalVar = 200;            // 普通全局变量，其他文件可以访问

void showVars() {
    cout << "在file1中 - 静态变量: " << fileLocalVar << endl;
    cout << "在file1中 - 全局变量: " << globalVar << endl;
}

// file2.cpp
#include <iostream>
using namespace std;
// 声明在file1.cpp中定义的变量
extern int globalVar;           // 正确：extern 声明其他文件的全局变量
// extern int fileLocalVar;     // 错误！无法访问其他文件的静态全局变量
// 声明在file1.cpp中定义的函数
extern void showVars();         // extern 声明其他文件的函数
void tryAccess() {
    cout << "在file2中 - 可以访问全局变量: " << globalVar << endl;
    // cout << fileLocalVar;    // 编译错误！无法访问静态全局变量
}

// main.cpp
#include <iostream>
using namespace std;
// 声明在其他文件中定义的函数
extern void showVars();
extern void tryAccess();
// 声明全局变量（如果需要使用）
extern int globalVar;
int main() {
    cout << "=== 程序开始 ===" << endl;
    cout << "在main中 - 全局变量: " << globalVar << endl;
    
    showVars();     // 调用file1.cpp中的函数
    tryAccess();    // 调用file2.cpp中的函数
    
    // 修改全局变量，观察所有文件中的变化
    globalVar = 999;
    cout << "修改后，在main中 - 全局变量: " << globalVar << endl;
    
    showVars();     // 再次调用，观察变化
    tryAccess();    // 再次调用，观察变化
    
    return 0;
}

一个小型的多文件程序，（一般NOI不涉及多文件），编译的时候一定要相关文件一起生成
g++ -o program file1.cpp file2.cpp main.cpp
extern只是声明，不是定义
它告诉编译器："这个变量/函数在别处定义了，相信我"
链接器负责找到实际的定义

```
运算和控制流程
```C
+   // 加
-   // 减
*   // 乘
/   // 除
%   // 取余
//自增、自减运算符
++i  // 先加1，再使用，int b = ++a;   假设a=5先变成6，然后 b = a=6
i++  // 先使用，再加1，int b = a++;   假设a=5先b=5，然后a变成6
--i  // 先减1，再使用
i--  // 先使用，再减1
//关系运算符号
==   // 等于
!=   // 不等于
>    // 大于
<    // 小于
>=   // 大于等于
<=   // 小于等于
//逻辑预算
&&   // 与（AND）
||   // 或（OR）
!    // 非（NOT）
//位运算
二进制的位运算，
a=172= 10101100
b=92 = 01011010
a&b    // 按位与，00001000 //11得1
a|b    // 按位或 ，11111110   //有1得1
a ^ b    // 按位异或 11110110  //同0非1
~a    // 按位取反，01010011 //全部反转
a << 2  // 左移，10110000 //地位用0代替，高位丢弃
a >> 3  // 右移，00010101 //高位用0代替，地位丢弃
//if控制
if (条件) {
    语句;
} else if (条件2) {
    语句2;
} else {
    语句3;
}
//条件（三目）运算符
int max = (a > b) ? a : b;  // max取较大值，简单规则

//switch，分类处理
int x = 2;
switch (x) {
    case 1: cout << "One"; break;
    case 2: cout << "Two"; break;
    case 3: cout << "Three"; break;
    default: cout << "Other";
}
//for循环
for (int i = 0; i < 5; i++) {
    语句;
}
循环数组快速
int a[5] = {1,2,3,4,5};
for (int i : a) cout << i << ' ';   // 输出 元素1 2 3 4 5，注意不是下标
//while 循环
int i = 0;
while (i < 5) {
    语句;
    i++;
}

//循环控制
break;   // 结束当前循环
continue; // 跳过本次循环，继续下一次


```




