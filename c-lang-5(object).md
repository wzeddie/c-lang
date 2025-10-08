# 学习内容上文回顾
计划学习路线：
基础语法 → STL容器与算法 → struct → [class基础→ 封装 → 构造析构 → 继承 → 多态 → 运算符重载] → 组合与项目实战
# 5. 了解c++面向对象的类、继承、多态，这种在实际软件工程用的很多的情况。 
「程序设计 → 软件设计」 的转折点。学习面向对象编程是让你从“会写程序”到“会设计系统”的关键一步。

>面向对象编程（Object-Oriented Programming, OOP）核心思想是：
“让程序中的数据和操作数据的方法封装在一起，模拟现实世界的对象关系。”

三大思想：类的封装（class Encapsulation），
| 支柱 | 英文            | 含义           | 举例                             |
| -- | ------------- | ------------ | ------------------------------ |
| 封装 | Encapsulation | 把数据和方法封成一个类  | 学生类里有姓名、成绩、计算平均分方法             |
| 继承 | Inheritance   | 子类继承父类的属性和方法 | 本科生继承学生类，并增加论文属性               |
| 多态 | Polymorphism  | 同一个接口，不同实现   | `Shape`类有`draw()`方法，不同子类各画不同形状 |


## 类和对象
学习内容：
定义类 (class)
类的访问权限控制
构造函数与析构函数
成员函数、成员变量
this 指针
对象的创建与访问
```c++
#include <iostream>  // 输入输出库
#include <string>    // 使用 string 类
using namespace std;

// 1. 定义类（class）
class Student {
private://私有,只能自己类访问，外部所有均不能访问，控制范围当前位置到public，这个范围
    // 定义成员变量（对象的属性）
    string name;   // 学生姓名
    int age;       // 年龄
    double score;  // 成绩

public://公开,所有类，控制范围当前位置到下一个访问权限控制符或类结束符，这个范围
    // 构造函数（对象创建时自动调用）
    // 构造函数名必须与类名相同，无返回值类型
    Student(string n, int a, double s) {
        // this 指针指向当前对象
        this->name = n;//(*this).name = n;  // 等价写法
        this->age = a;
        this->score = s;
        cout << "✅ 构造函数被调用：创建学生对象 " << name << endl;
    }
    // 3. 析构函数（对象销毁时自动调用）
    // 析构函数以 ~ 开头，用来清理资源
    ~Student() {
        cout << "🗑️ 析构函数被调用：销毁学生对象 " << name << endl;
    }
    //  4. 成员函数（对象的行为/方法）
    void showInfo() {
        cout << "姓名：" << name
             << "，年龄：" << age
             << "，成绩：" << score << endl;
    }
    void setScore(double newScore) {
        // 使用 this 指针区分成员变量和参数
        this->score = newScore;
    }
    double getScore() {
        return this->score;
    }
};

// 5. 主函数：对象的创建与访问
int main() {
    // 创建对象（会自动调用构造函数）
    Student stu1("张三", 18, 92.5);
    // 不能这样设置，stu1.name = "李四"; 因为是私有，上文提过。
    // 访问成员函数
    stu1.showInfo();
    // 修改成绩
    stu1.setScore(95.0);
    // 获取成绩
    cout << "修改后的成绩：" << stu1.getScore() << endl;
    // 当 main() 结束时，stu1 被销毁 → 自动调用析构函数
    return 0;
}

```

## 封装和访问控制
学习内容：
public, private, protected 区别
setter/getter 方法
const 成员函数
mutable、static 成员变量与函数
✅ 练习：写一个 BankAccount 类，支持存钱、取钱、查询余额。
## 继承
学习内容：
基类（父类）与派生类（子类）
public、protected、private 继承方式
构造与析构的调用顺序
成员隐藏与同名覆盖
✅ 练习：Person → Student → GraduateStudent 三层继承结构。
## 多态
学习内容：
虚函数 virtual
函数重写（override）
纯虚函数与抽象类
动态绑定与基类指针
析构函数的虚函数必要性
✅ 练习：Shape 基类 + Circle / Rectangle 子类，实现 draw() 的多态。

## 运算符重载
目标：让对象像基本类型一样使用。
学习内容：
重载 +、-、==、<< 等运算符
友元函数（friend）
输入输出流重载
✅ 练习：Complex 类重载加减号，实现复数运算。

## 标准库中与面向对象的关系
标准库的大部分都是类封装的对象，体现封装、构造/析构、多态、运算符重载等 OOP 思想。
vector<int> v = {5, 2, 9};//创建了vector的实例对象
sort(v.begin(), v.end()); //调用对象的方法操作迭，支持对象存储和操作