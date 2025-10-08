# Algorithm 算法
算法定义,算法 = 解决问题的思路 + 实现过程。 比如：
- 排序算法 → “如何让一堆数据从小到大排好”  
- 查找算法 → “如何在数据中快速找到目标值”  
- 贪心算法 → “如何在每一步都取最优，从而逼近全局最优”   

学习算法的哪些内容？算法思想，算法时间复杂度，空间复杂度  

## 排序算法 Sorting Algorithm
是一种将一组无序数据重新排列成有序序列的算法。
```c++
默认一般快速排序
sort(a.begin(), a.end());//半包的容器[起始地址,末尾地址+1）  
```

### 快速排序的核心思想
1. 以一个“基准”元素（pivot）为中心，把数组分为两边：小于 pivot 的在左，大于 pivot 的在右；
   - 把一串数字排队，挑一个“队长”（pivot）。然后把比队长“矮”的放左边，比队长“高”的放右边。
2. 对左右子区间继续进行递归排序
   - 左右两边子队伍，再各自重复同样动作（递归，直到区间长度变小）
3. 当区间很小（如长度 < 4）时，自动切换为当前区间手动插入排序（Insertion Sort）；
   - 当子队伍很小的时候，改用插入排序，手工更快
4. 极端情况，如果递归过深（数据分布极端），自动改用堆排序（Heap Sort） 
   - 当发现队伍一直分不均，递归太深时，改动堆排序保证最坏时间的办法
### 通俗的解释快速排序
假如需要对某一队伍进行排序，你说：
“中间这位同学，你来当‘分界线’（pivot）！，所有比他矮的站他左边，比他高的站右边。”
排好以后：
然后左边和右边各小组，再选一个“分界线”继续分。
....直到小组里面只有1人，无法分。
### 时间复杂度
O(nlogn)
### 示意图步骤演示
推荐看《hell算法》这本书，里面有动画示意图，效果更好，更容易理解。  
```c++
a = [9, 3, 7, 1, 5, 2, 8, 6, 4]
索引:  0  1  2  3  4  5  6  7  8
双向指：i ->                  <-j
1.设立中间位置基准线，pivot = a[(l+r)/2]，a[4]=5，设立i=0，j=8两个移动指针
2.把i++直到a[i]碰到基准线，这期间如有a[i]大于中间基准线5的，且i的位置又在j的左边（i<=j），说明排序错误，要被交换到右边去。
3.把j--直到a[j]碰到基准线，这期间如有a[j]小于中间基准线5的，且j的位置又在i的右边(j>=i)，说明排序错误，要被交换到左边去。
4.循环终止条件：i > j，循环终止。

具体步骤演示
中位基准线:a[(0+8)/2]=a[4]=5,i循环[0,4],j循环[4,8]
两个子区间[9, 3, 7, 1]和[2, 8, 6, 4]
1.开始查找
a[0]=9>5,找一个大于基准线的
a[8]=4<5,到一个小于基准线的
0<=8，说明位置排错，应该交换
[4, 3, 7, 1, 5, 2, 8, 6, 9]
   i=1,              j=7
2.继续查找
a[2]=7>5，找一个大于基准线的
a[5]=2<5,找到一个小于基准线的
i<=j，说明位置排错，应该交换
[4, 3, 2, 1, 5, 7, 8, 6, 9]
 0  1  2  3  4  5  6  7  8  --索引 
          i  j
3.继续查找
a[i]=1,不交换,i++,i=4
a[j]=5,不交换,j--,j=3
i>J,触发循环结束
第一次递归结果：
                 [9,3,7,1,5,2,8,6,4]
                          |
                   pivot = 5
                  /           \
         [4,3,2,1]          [7,8,6,9]

//继续递归处理左右两边
左子区间段：索引 0..3 → [4,3,2,1]
基准线a[(0+3)/2]=a[1]=3，i=[0,1],j=[1,3]
分为两个子区间:[4]和[2,1]
第一次循环
[1,3,2,4]
   i j
第二次循环
a[i]=3
a[j]=2，2小于基准线3
i<=j,1<=2，继续交换
[1,2,3,4]
   j i
触发循环终止，得到新的两个子区间[1,2]和[4]，左边[1,2]继续递归，右边元素只有一个，不递归，返回

右子区间段：索引 0..3 → [7,8,6,9]
//同理，核心满足条件：
a[i] >= pivot, a[j] <= pivot 且 i ≤ j
完整的递归示意图：
                               [9,3,7,1,5,2,8,6,4]
                                        |
                                    pivot=5
                              /                   \
                        [4,3,2,1]                [7,8,6,9]
                           |                         |
                        pivot=a[3/2]=a[1]=3                   pivot=8
                       /      \                 /        \
                  [1,2]       [4]           [7,6]         [9]
                     |                         |
                  pivot=a[(0+1)/2]=a[0]=1    pivot=7
                  /      \                 /      \
                []       [2]            [6]       []






//极端情况出发堆排序，假设基准线又始终选择最左边
[1, 2, 3, 4, 5, 6, 7, 8, 9]
a[0]=1
左边: []（空）
右边: [2,3,4,5,6,7,8,9]
继续递归
a[0]=2
左边: []（空）
右边: [3,4,5,6,7,8,9]
......
递归就要跑 n 层
原本希望 O(n log n) 的复杂度，变成了 O(n²)！，还不如切换为堆排序。

```

### 基础用法示例
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {5, 3, 8, 1, 2};
    // 升序排序（默认）
    sort(a.begin(), a.end());
    cout << "升序排序结果: ";
    for (int x : a) cout << x << " ";
    cout << endl;
    // 降序排序
    sort(a.begin(), a.end(), greater<int>());
    cout << "降序排序结果: ";
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}

升序排序结果: 1 2 3 5 8 
降序排序结果: 8 5 3 2 1

**排序特殊用法：自定义排序方式，可选参数

sort(起始迭代器, 结束迭代器, 比较方式);
比较方式=比较函数：决定“两个元素谁在前”的规则

struct Student {
    string name;
    int score;
    int age;
};
// 自定义比较函数
bool compareByScore(Student a, Student b) {
    return a.score > b.score;  // 成绩高的排前面（降序），返回 true，表示 a 应该排在 b 前面。
}
vector<Student> v = {
        {"Alice", 85, 20},
        {"Bob", 90, 19},
        {"Cindy", 78, 21}
    };

sort(v.begin(), v.end(), compareByScore);
//输出：
Bob 90 19
Alice 85 20
Cindy 78 21

//衍生，多条件排序
bool compare(Student a, Student b) {
    if (a.score == b.score)
        return a.age < b.age;  // 成绩相同 -> 年龄小的排前面
    return a.score > b.score;  // 成绩高的排前面
}


```
常见的sort其他算法：  
| 算法函数          | 平均复杂度      | 稳定性 | 适用场景       |
| ---------------- | ---------- | --- | -------------- |
| `sort()`         | O(n log n) | 否   | 通用、竞赛最常用       |
| `stable_sort()`  | O(n log n) | 是   | 多关键字排序（要求顺序稳定） |
| `partial_sort()` | O(n log k) | 否   | 仅需前 K 名        |
| `nth_element()`  | O(n)       | 否   | 仅需第 K 小元素      |

## 二分查找算法 binary_search
功能：判断一个有序序列中，是否存在某个指定的元素。如果存在，返回 true；否则返回 false
前提：二分查找的前提，一定是完成排序的
## 算法通俗解释
可以想象成在字典里查单词的过程。（字典已经默认按单词字母排序）
如果要查 “peach”：
先打开中间那一页；
如果看到 “grape” → “grape” 比 “peach” 靠前，那就翻右边；
如果看到 “pear” → “pear” 比 “peach” 靠后，那就翻左边；
每次查找都能排除掉一半的范围。
## 时间复杂度
O(log n)
## 示意图步骤演示
```c++
std::vector<std::string> dictionary = {
    "apple", "banana", "grape", "peach", "pear", "plum"
       0        1         2        3        4       5   -索引
       i                                             j
};
初始：i=0，j=5
翻页：i=0，j=5
(i+j)/2=2，dictionary[2]=grape 比目标小，把i指向grape+1位置，继续
翻页：
i=3，j=5
(i+j)/2=4，dictionary[4]=pear，比目标大，把j指向pear-1，继续
翻页：
i=3，j=3
(i+j)/2=3，dictionary[3]=pear，找到目标值，返回成功

当i>j,会终止查找
假设数组 [1, 3, 5, 7, 9]，查找 6：
初始： left=0, right=4, mid=2 → a[2]=5 < 6 → left=mid+1=3
下一轮： left=3, right=4, mid=3 → a[3]=7 > 6 → right=mid-1=2
[1, 3, 5, 7, 9]
       j  i
此时： left=3, right=2 → left > right ✅ 终止

```

### 简单代码使用
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 3, 5, 7, 9};

    // 必须保证 a 是有序的
    sort(a.begin(), a.end());

    cout << binary_search(a.begin(), a.end(), 3) << endl; // 输出 1（true）
    cout << binary_search(a.begin(), a.end(), 4) << endl; // 输出 0（false）
}

```
### 二分查找的其他算法
都是利用二分查找法思想
lower_bound：找到第一个大于（>= target）的位置，lower_bound → 找“下界”
upper_bound: 找到第一个大于 (> target)的位置，upper_bound → 找“上界”

```c++
初始：
[1  3  3  5  7  9]
 L              R

步骤1：mid=2, a[mid]=3 >=3 → 往左
[1  3  3  5  7  9]
 L     R
       ^
       
步骤2：mid=0, a[mid]=1 <3 → 往右
[1  3  3  5  7  9]
     L R
       ^
       
步骤3：mid=1, a[mid]=3 >=3 → 往左
[1  3  3  5  7  9]
     L R=0
返回下标 left=1

每次比较：
如果 mid >= target → 往左缩小范围
如果 mid < target → 往右缩小范围
循环终止时，left 就是答案

auto it = lower_bound(a.begin(), a.end(), 5); 
// it 指向值 >= 5 的第一个元素，返回是5的位置
auto it = upper_bound(a.begin(), a.end(), 5); 
// it 指向值 > 5 的第一个元素，返回的是7的位置

//自定义查找
auto it = lower_bound(container.begin(), container.end(), value, compareFunction);

compareFunction 接收两个参数：容器中的元素，查找目标值（或者另一元素）
struct Student {
    string name;
    int mathScore;
};

vector<Student> students = {
    {"Alice", 85},
    {"Bob", 92},
    {"Charlie", 78},
    {"David", 92}
};
//自定义查找
bool cmpStudentScore(const Student &s, int targetScore) {
    return s.mathScore < targetScore;
}
告诉 lower_bound：
如果当前学生成绩 < 目标成绩（返回true） → 继续往右查找
否则 → 停在当前位置（就是第一个成绩 ≥ targetScore 的学生）
//调用
int targetScore = 90;
auto it = lower_bound(students.begin(), students.end(), targetScore, cmpStudentScore);

```
## 贪心算法Greedy Algorithm
在每一步选择中都采取 当前看起来最优的选择，希望通过局部最优得到全局最优。
常用于求最短路径、最小硬币找零、活动安排、任务调度等问题
例如：
找零问题 → 每次选当前最大硬币
活动安排问题 → 每次选最早结束的活动
背包问题（单位价值最大） → 每次选性价比最高的物品

所以贪心算法，在算法库中没有现成，需要自己实现逻辑。
很多贪心问题需要先对元素排序、查找，然后在根据贪心策略进行解题。
## 算法通俗解释
举例
找零问题：假设要找 63 元零钱，硬币面值：25, 10, 5, 1 元
贪心策略：
先用最大面值硬币 25 元：取 2 枚 → 50 元
剩下 13 元 → 用 10 元硬币 1 枚 → 剩下 3 元
用 1 元硬币 3 枚 → 总共 6 枚硬币
核心思想，每一步贪心，选当前最大能用的面值，不回头，不做全局搜索


------

## 其他算法  
next_permutation、unique、reverse（字典序全排列、去重复、反转）  
merge（归并）、min_element / max_element(归并、最小值、最大值)  