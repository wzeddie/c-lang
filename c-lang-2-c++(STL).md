# 一、C++基础：
编译型语言/解释型语言、静态语言/动态语言、基础数据类型、数组（基础数据类型+[]）、函数、<u>指针</u>、**局部/全局变量**，位运算、输入输出、控制语法、运算语法，内容同c语言

# 二、C++核心：常见STL容器、struct结构体、algorithm算法、标准库、面向对象
## 1. 学习 STL（标准模版库）的常见容器  

`vector` 就是会**自动长大**的数组=动态数组Dynamic Array ，底层实现`连续的内存块`，  `类似`python的list/java的ArrayList/JS的Array   
`set` 就是插入时会自动**去重并排序**的「集合」,底层实现`二叉树`。  `类似`python的set（无序）/类似java的TreeSet（有序）或HashSet（无序）/JS的set        
`map` 就是插入时会**自动排序**的「键:值字典」，底层实现`二叉树`。  `类似`python的dict，（左边是单词，右边是单词的解释）/JS的object/java的map    
>作为 STL 入门，这三者大概覆盖了信息学竞赛里 70%的常见数据类型的需求。

| 容器         | 竞赛常用场景                                              |
| ---------- | --------------------------------------------------- |
| **vector** | 存储动态序列、实现数组操作、快速下标访问、模拟矩阵/图的邻接表等。绝大多数涉及序列的题目都可以用它。  |
| **set**    | 存储**唯一元素集合**，自动排序，快速查找、去重、求交集/并集、判断存在性，常用在离散化、去重问题。 |
| **map**    | 键值映射，频率统计、编号映射、哈希表替代品，常用于统计、压缩映射、快速查询。              |
>其他30%的场景，主要是涉及双端队列、栈、队列、优先队列等。  

一句话概况容器：`vector → 序列，set → 唯一集合，map → 键值字典`

## 2. 学习`algorithm`算法库   
algorithm库，提供的排序、二分、最值、排列、前缀、差分、去重、反转、集合运算、随机洗牌等几十种经典算法。 其中有10中是基础的常用的算法思想：   
`sort + binary_search`（排序和查找）  
`lower_bound / upper_bound`（第一个≥目标值和第一个>目标值，基于二分查找）  
`next_permutation、unique、reverse`（字典序全排列、去重复、反转）  
`merge（归并）、min_element / max_element`(归并、最小值、最大值)  
>这10种算法入门，这些大概能覆盖80%的NOI算法需求，
一句话概况：很多NOI基础题，本质就是`sort（排序）+Binary Search（二分查找）+Greedy（贪心）`的算法组合。因为排序后，数据有序，便于快速查找和比较，在有序数据上选择局部最优策略，比如：最少操作、最大收益、最大任务调度等。
## 3. 学习 struct  结构体  
C/C++ 内置类型（int、double、char、string）只能描述单一数据，但在现实问题里经常需要把多个**不同类型（或相同类型）**的变量捆在一起当作一个整体，比如坐标体系（x，y）、学生成绩（name，math_scores，english_scores）、图的一条边（node_start，node_end，distance）等。    
struct（structure 的缩写）就是语言层面提供的“用户自定义聚合类型”机制，用来打包、组织、封装这些数据。  
```c++
//自定义结构体数据类型，支持混合
struct Point {
    int x;
    int y;
};
//调用
Point p1;
p1.x = 10;
p1.y = 20;
```
##  NOI 小结
>`NOI竞赛=STL+algorithm+struct`，STL提供容器，algorithm提供算法，struct自定义数据形态，三者组合几乎解决90%（基础+中等难度）的NIO竞赛需求。  
>剩下是一些高难度的，特别是图论、数论、大规模数据结构（千万级数据），必须依赖自己实现的算法与复杂数据结构。  

补充说明，竞赛重算法与性能，现实应用侧重：实际问题更多依赖成熟系统、工程实现、稳定性与可维护性。 
1. 竞赛中高难度的题目，解决的是时间复杂度、空间限制和算法逻辑组合的问题。因为时间、内存条件限制 
2. 但在现实社会中，图论、数论、大规模数据结构，是直接使用专业、成熟的软件来实现。  
   图论：GIS 系统、交通导航软件、网络路由算法库  
   数论：密码学库、数学软件（如 Mathematica、SageMath）  
   大规模数据结构：数据库、缓存系统、索引结构  
## 4. 了解c++提供了哪些标准库，分别干什么用  
## 5. 了解c++面向对象的类、继承、多态，这种在实际软件工程用的很多的情况。  

## **STL（标准数据类型库）容器**
前期历史：C语言没有统一标准，每个人手写各种数据结构（动态数组、字典、集合、链表、栈、队列、树等），耗时费力，大量重复性工作。   
c++早期是为了解决面向对象问题，仍然缺少通用的数据结构与算法库。  
后来为了避免重复造轮子，保证效率和安全，统一标准，于是C++ 标准委员会在 1998年（C++98标准） 中正式引入了 STL，成为 C++ 的核心组成部分。   
Standard Template Library（标准模板库），简单理解C++提供的几套现成`数据结构 + 常用方法`的模板，存储和使用数据的时候拿来就用。   

### 常见STL容器分类
- （1）顺序容器（数据有序存放，按插入顺序排列）  
`vector`：动态数组（最常用）。  
deque：双端队列（偶尔用）。  
- （2）<u>**有序**</u>关联容器（自动排序）  
`set`：不重复集合，自动排序。  
`map`：键值对（key → value），键唯一，自动排序。  
- （3）<u>**无序**</u>关联容器（C++11，基于哈希表，查找更快）  
unordered_set：不重复集合，查找平均 O(1)，但无序。  
unordered_map：键值对（哈希表），查找更快但无序。  

- （4）容器适配器（对其他容器的包装）  
不是存储数据的新容器，而是把已有容器（通常是 vector、deque 或 list）包装成特定的数据结构：栈、队列、优先队列等。  
stack —— 栈（后进先出，LIFO）。  
queue —— 队列（先进先出，FIFO）。  
priority_queue —— 优先队列（常用来取TOP最大/最小值）。  
> - （5）特殊STL   
> C++的string，本质上就是STL一种，只是比较特殊化，比如定义方式上特殊格式。string s；别人是vector<int> a;用+号拼接等等。string是STL的亲儿子，仅此特殊对待。  
### 容器的通用定义
  
模板名<数据类型> 对象名;   
```C
vector<int> v;        // 动态数组  
string s;             // 字符序列（特例，不用<>）  
set<int> s;           // 有序唯一集合  
map<string,int> m;    // 键值对表 
``` 
### 容器的通用特性  
1️⃣ 基本操作
| 操作   | 语法 / 方法              | 说明 / 适用容器 | 备注                                           |
| ---- | ------------------------------- | --------- | -------------------------------------------- |
| 插入   | `c.insert(x);` / `v.push_back(x);`  | 插入元素      | `insert`：set/map 通用，`push_back`：vector/deque |
| 删除   | `c.erase(x);` / `v.pop_back();`     | 删除元素或末尾   | `erase`：set/map/vector，`pop_back`：顺序容器       |
| 清空   | `c.clear();`                        | 清空容器      | 所有 STL 容器通用                                  |
| 判断空  | `c.empty()`                         | 是否为空      | 所有 STL 容器通用                                  |
| 元素个数 | `c.size()`                          | 返回元素数量    | 所有 STL 容器通用                                  |
2️⃣ 元素访问
| 操作       | 语法            | 说明 / 适用容器           | 备注                                  |
| ------- | ------------- | ------------------- | --------------------------------- |
| 下标访问   | `v[i]`        | 获取元素                | 顺序容器（vector/array/deque）            |
| 范围检查访问 | `v.at(i)`     | 获取元素，越界抛异常          | 顺序容器                                |
| 获取首元素  | `*c.begin()`  | 第一个元素          | c.begin返回迭代器，是地址，加*取的是第一个元素值                      |
| 获取尾元素  | `*c.rbegin()` | 最后一个元素         | 同上                      |
| 查找     | `c.find(x)`   | 返回迭代器，找不到返回 `end()` | set/map/unordered_map/unordered_set |
| 计数     | `c.count(x)`  | 返回出现次数              | set/multiset/map/multimap           |

### 迭代器Iterators   
迭代:是逐个访问序列中元素的过程。遍历元素的过程
数组的下标循环就是最常见的迭代方式：for (int i = 0; i < 3; ++i)  

但是在c语言中下标循环只适合能用下标访问的容器（如 array, vector, deque）。   
有些set、map这些底层是二叉树结构，不能通过下标访问set[0]，比如：set<int> s = {10, 5, 20};可能在内存的存储样子这样：
```
        10
       /  \
      5   20
```
s.begin() → 指向最小的元素（5） //有序  
++迭代器 → 跳到下一个节点（10）  
这种遍历要靠树结构来遍历走，而不是靠内存偏移=下标循环s[0]对他们没有意义。  

`迭代器`，统一了不同容器的遍历方式，本质上是一个“指针的抽象”，可以指向容器中的元素，并能前进（++）、后退（--）。
```c++
//c++迭代器用法
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}
//python迭代器用法
s = {1, 2, 3, 4}
it = iter(s)      # 获取s的迭代器对象
while True:
    try:
        x = next(it)   # 获取下一个元素
        print(x, end=" ")
    except StopIteration:
        break
//迭代器用不习惯怎么办
类似用c++的for（int i：a），因为背后编译器会自动转成迭代器形式。
但是格式要统一为：auto x : c    //c代表所有类型容器，比如map
map<string, int> m = {{"apple", 5}, {"banana", 10}, {"pear", 20}};
    for (auto p : m) {   
        cout << p.first << " -> " << p.second << "\n";
    }
```


## `vectord动态数组`
名称来源：  
vector数学向量：v=(v1​,v2​,…,vn​)是一组有序数值。常见写  $v_i$ 来表示第i个元素，但这是抽象概念，  

早期 STL 设计者借用了数学术语，强调它是一段线性、连续、可随机访问的数据序列，就像“向量”一样。

但是实际跟数学上的“向量”没有真正的关系，不是向量运算的概念，就是一个长度动态可变的连续存储数组。  
底层实现:连续的内存块
```C++
vector<int> v = {1,2,3};
内存地址 →   100   104   108   112   116  //为什么是4个单位，int型占用
v[i]       [ 1 |  2 |  3 |    ? |   ? ]
```
vector与一般数组比如 int[10] string[10] 有什么区别吗  

✅ 更灵活：vector 可以初始化为空，普通数组必须声明长度。  
✅ 动态扩展：可以 push_back / resize，数组长度固定。  
✅ 自动内存管理：不需要手动 delete[]，C++ 管理内存。  
✅ 成员函数丰富：如 .size() .clear() .insert() .erase()。  
```c++
vector 语法
vector<类型> 变量名;
vector<int> v ;   //存{1,2,3}
vector<string> names;   //{"abc","hello","world"}     
vector<double> num;    //{1.2,1.34,2.22}    
-----

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. 初始化
    vector<int> v1;             // 空vector
    vector<int> v2(5);          // 5个元素，默认值0
    vector<int> v3(5, 42);      // 5个元素，每个都是42
    vector<int> v4 = {1, 2, 3}; // 列表初始化

    // 2. 添加和删除
    v4.push_back(4);   // 尾部添加
    v4.pop_back();     // 删除最后一个元素

    // 3. 随机访问
    cout << v4[0] << endl;     // 下标访问
    cout << v4.at(1) << endl;  // 安全访问（推荐）
    cout << "首元素=" << v4.front() << ", 尾元素=" << v4.back() << endl;

    // 4. for遍历
    for (int x : v4) cout << x << " ";
    cout << endl;
    //迭代器遍历
    for (auto it = v4.begin(); it != v4.end(); ++it)
        cout << *it << " ";//取值，不是取地址
    cout << endl;

    // 5. 尺寸 & 容量
    cout << "大小 size=" << v4.size() << endl;//已存储元素个数
    cout << "容量 capacity=" << v4.capacity() << endl;//内存能容纳的元素个数

    // 6. 插入和删除
    v4.insert(v4.begin() + 1, 99);          // 在第二个位置插入99
    v4.erase(v4.begin());                   // 删除第一个元素
    if (v4.size() >= 5)
        v4.erase(v4.begin() + 2, v4.begin() + 5); // 删除 [2,5) 范围

    // 7. resize
    v4.resize(10);       // 变成10个元素
    v4.resize(3, 100);   // 变成3个元素，值为100

    // 8. 交换
    vector<int> v5 = {7, 8, 9};
    v4.swap(v5);

    // 9. 清空
    v4.clear();  
    cout << "是否为空？ " << v4.empty() << endl;

    return 0;
}



二维vector数组
用 vector<vector<T>> 来实现二维数组（T 可以是 int、double、string 或自定义类型）
#include <bits/stdc++.h>
using namespace std;

int main() {
vector<vector<int>> mat;

mat.push_back(vector<int>{1,2,3});  // 添加第一行
mat.push_back(vector<int>{4,5,6});  // 添加第二行

cout << mat[0][1] << endl; // 输出 2

    return 0;
}


```
二维数组的常用操作
| 操作       | 示例                                     |
| -------- | -------------------------------------- |
| 访问元素     | `mat[i][j]`                            |
| 获取行数     | `mat.size()`                           |
| 获取列数（某行） | `mat[i].size()`                        |
| 修改元素     | `mat[i][j] = 5`                        |
| 遍历元素     | `for(auto &row: mat) for(auto x: row)` |
| 添加新行     | `mat.push_back(vector<int>(cols, 0))`  |
| 清空矩阵     | `mat.clear()`                          |

## `string类型`
string 是STL的一个特殊的容器类型。
定义格式:string s;             // 字符序列（特例，不用<>）
```c
#include <iostream>   // cin/cout
#include <string>     // string
#include <algorithm>  // 引入sort排序算法
using namespace std;

int main() {
    string s1 = "hello";
    string s2 = "world";
    // 拼接
    string s3 = s1 + ", " + s2;
    cout << s3 << endl; // hello, world
    // 子串
    cout << s3.substr(7, 5) << endl; // world
    // 查找
    cout << s3.find("lo") << endl; // 3
    // 修改
    s1[0] = 'H';
    s1.append("!!!");
    cout << s1 << endl; // Hello!!!
    // 排序字符
    sort(s2.begin(), s2.end());
    cout << s2 << endl; // dlorw

    return 0;
}
string特殊操作
s.substr(pos, len)：子串
s.find("abc")：查找
s + "world"：拼接
```

## `set`
名称来源：在数学和计算机里，set 更常见的意思就是“集合”，而不是“设置”。the set of natural numbers （自然数集合）有些语言叫collection，也是集合的概念。  
定义：set 是一个**有序集合**，内部元素**自动排序**，**元素唯一**，已有元素不能修改。    
底层实现：二叉树  
不支持下标访问，只能通过迭代器访问元素  
特点：  
元素唯一（不能重复），插入重复值，直接无视  
元素有序（默认升序，可自定义降序）。  
不能修改某个元素的值（因为改值会破坏有序性），只能删除旧，添加新的元素。  
常见应用：快速去重、自动排序、查找某个元素是否存在。O（log n）  

```c++
set<int> s;          // 存 int
set<string> s2;      // 存 string
set<double> s3;      // 存 double
——————————
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. 初始化
    set<int> s1;                 // 空 set
    set<int> s2 = {3, 1, 4, 1}; // 列表初始化，重复元素自动去掉1
    set<int> s3(s2);             // 拷贝构造

    // 2. 插入
    s1.insert(10);
    s1.insert(5);
    s1.insert(20);

    // 3. 删除
    s1.erase(5);                 // 删除元素5
    // 范围删除：删除小于15的所有元素
    auto it = s1.lower_bound(15);  // >=15 的第一个位置
    s1.erase(s1.begin(), it);

    // 4. 查找
    if (s2.find(3) != s2.end()) {
        cout << "3 存在于 s2 中" << endl;
    } else {
        cout << "3 不存在" << endl;
    }

    // 5. 计数（set中0或1）
    cout << "元素4出现次数: " << s2.count(4) << endl;

    // 6. 遍历（范围 for）
    for (int x : s2) cout << x << " ";  // 输出有序集合
    cout << endl;

    // 7. 遍历（迭代器）
    for (auto it = s2.begin(); it != s2.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // 8. 首尾元素
    cout << "首元素 front: " << *s2.begin() << endl;
    cout << "尾元素 back: " << *s2.rbegin() << endl;

    // 9. 清空 & 判断是否为空
    s1.clear();
    cout << "s1 是否为空? " << s1.empty() << endl;

    // 10. 大小
    cout << "s2大小: " << s2.size() << endl;

    return 0;
}


二维set，结合vector
set<vector<int>> s;

s.insert({1, 2, 3});
s.insert({2, 3, 4});
s.insert({1, 2, 3}); // 去重

for (auto &v : s) {
    for (int x : v) cout << x << " ";
    cout << endl;
}
set<int, greater<int>> s2; // 降序集合
```
## `map`
名称来源：mapping，映射关系或映射函数，he mapping from students to grades
map 是一个容器，表示 从 key 到 value 的映射关系。
```c
map<string, int> m;
m["Alice"] = 95;
m["Bob"] = 88;
```
类型：有序键值对（key → value），键唯一  
底层实现：二叉树 map<int, string>,节点存储一个 (key, value) 对  
```
          (5, "five")
         /           \
 (2,"two")         (8,"eight")
    /    \
(1,"one") (3,"three")
```

不支持通过下标访问 key（只能通过 operator[] 或迭代器访问）  
适用场景：快速查找、计数、映射关系存储（映射关系：如学号-姓名、单词-次数、商品ID-价格。）  
1. 特点：  
键（key）是唯一的，不能重复。  
内部基于 （有序平衡二叉树） 实现，所以 **自动按 key 排序**。  
定义方式：   
map<key类型, value类型> 容器名;  

```c++
#include <iostream>
#include <map>
using namespace std;


int main() {
    
    // 1. 初始化
    map<string, int> m1;                  // 空 map
    map<string, int> m2 = {{"apple", 5}, {"banana", 10}}; // 列表初始化
    map<string, int> m3(m2);              // 拷贝构造

    // 2. 插入
    m1.insert({"pear", 20});               // 用 pair 插入
    m1["orange"] = 15;                     // operator[] 插入或修改

    // 3. 修改
    m1["pear"] = 25;                       // 修改已存在的 key 对应的 value

    // 4. 删除
    m1.erase("orange");                     // 删除指定 key
    // 范围删除（迭代器）
    auto it = m1.lower_bound("pear");      // >= "pear"
    m1.erase(m1.begin(), it);              // 删除起始到 it 之前的元素

    // 5. 查找
    if (m2.find("apple") != m2.end()) {
        cout << "apple存在，值=" << m2["apple"] << endl;
    }
    // 6. 计数
    cout << "apple出现次数: " << m2.count("apple") << endl; // map中0或1
    // 7. 遍历（范围 for）
    for (auto p : m2) cout << p.first << " -> " << p.second << endl;
    // 8. 遍历（迭代器）
    for (auto it = m2.begin(); it != m2.end(); ++it)
        cout << it->first << " -> " << it->second << endl;
    // 9. 首尾元素
    cout << "首元素 front: " << m2.begin()->first << " -> " << m2.begin()->second << endl;
    cout << "尾元素 back: " << m2.rbegin()->first << " -> " << m2.rbegin()->second << endl;
    // 10. 清空 & 判断是否为空
    m1.clear();
    cout << "m1是否为空? " << m1.empty() << endl;
    // 11. 大小
    cout << "m2大小: " << m2.size() << endl;
    return 0;
}


```
小结，除了vector set map，当然还有装容器的各种外包装  
stack —— 栈（后进先出，LIFO）。   
queue —— 队列（先进先出，FIFO）。  
priority_queue —— 优先队列（常用来取TOP最大/最小值）  

## struct自定义结构体  
标准 STL 容器定义时必须指定类型，不能直接混合 int 和 string  
C/C++ 内置类型（int、double…）只能描述单一数据，而现实问题里经常需要把多个不同类型（或相同类型）的变量捆在一起当作一个整体（二维点、学生记录、图的一条边…）  
如果需要混合：struct 结构体  
```
struct Node {
    int id;
    string name;
};

vector<Node> v;
```
写竞赛代码，先写 struct，再丢进 vector/set/map，几乎成了标准流程。  



