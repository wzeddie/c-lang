# NOI例题
>已经学习了STL，struct,排序、查找、贪心算法   
>一道例题，同时用到：vector、set、map、sort、struct,lower_bound 和 贪心算法。
## 题目1：任务分配最小成本问题
一个公司有若干个`任务`tasks需要完成，每个任务需要不同的“技能等级”skill才能完成。    
同时这个公司有若干`员工`，每个员工也有一个对应的“技能等级”skill和“薪资成本”cost。  
现在公司要以`·尽量低的总成本·`totalCost完成所有任务，每个任务分配一个满足要求的员工。
求这个公司最小总成本是多少？
### 程序化题目
```C
用户数据结构来程序化题目：
公司有n个任务，用vector表示任务的skill技能等级。定义n个任务tasks 
vector<int>  tasks={3,7,9};

公司有m个员工，用struct自定义员工的技能等级和薪资水平
struct Employee {
    int skill;
    int cost;
};
初始化有m个员工变量employees
vector<Employee> employees = {
        {5, 10},
        {8, 20},
        {10, 15},
        {7, 18}
    };
定义总成本
  int totalCost = 0;
定义已用员工，记录下标，set有唯一性。
set<int> used;

核心思路涉及算法：
所有 employees、task 已按技能升序排列；
循环对于每个任务 task：
- lower_bound() 直接找到第一个 skill >= task 的员工；
- 从这个位置往后找出成本最低的员工；因为已经排序后面的skill肯定大于task，然后取找cost最小的值，且员工未分配任务。
- 找到最小cost，记录并标记为已用员工；
- 计算cost所有任务的总成本。
```

### 完整的代码

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Employee {
    int skill;
    int cost;
};
//自定义sort排序算法，按skill升序
bool compareBySkill(Employee a, Employee b) {//Y也可以传递地址形式，Employee &a 
    return a.skill < b.skill;
}
//自定义查找方法，
bool cmpLowerBound(const Employee &e, int task) {//为什么要通过&e传递容器地址，为了效率，传Employee e，也可以，但是Employee e是复制容器e，生成新的容器e，不是直接传递e的地址。

    return e.skill < task;//如果skill小于task，则查找范围右移，直到找到第一个等于task的
    //等同于，“如果当前员工技能值 < 任务要求，那么查找范围向右移动（跳过这个员工）。”
    //即：返回第一个 skill ≥ task 的员工的位置。
}

int main() {
    vector<int> tasks = {3, 7, 9};
    vector<Employee> employees = {
        {5, 10},
        {8, 20},
        {10, 15},
        {7, 18}
    };
    sort(tasks.begin(), tasks.end());//排序，升序
    sort(employees.begin(), employees.end(), compareBySkill);//排序按skiil升序

    int totalCost = 0;
    set<int> used;
lower_bound
    for (int task : tasks) {
        // 使用 lower_bound 找到第一个技能 >= 当前任务的员工
        auto it =lower_bound (employees.begin(), employees.end(), task, cmpLowerBound);

        int minCost = 1e9;
        int chosen = -1;
        //因为employees已排序，从it往后找到skill肯定大于task，开始找cost最低的员工
        // 使用下标访问employees
        // distance(employees.begin(), it)计算i的起始位置
        for (int i = distance(employees.begin(), it); i < employees.size(); i++) {
            if (used.count(i)) continue; // 如果员工已分配，则跳过
            if (employees[i].skill >= task && employees[i].cost < minCost) {
                minCost = employees[i].cost;
                chosen = i;
            }
        }

        if (chosen == -1) {
            cout << "❌ 无法完成所有任务" << endl;
            return 0;
        }

        used.insert(chosen);
        totalCost += employees[chosen].cost;
    }

    cout << "✅ 完成所有任务的最小总成本为: " << totalCost << endl;
    return 0;
}

```


```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// 定义员工结构体
struct Employee {
    int skill;  // 技能值
    int cost;   // 成本（雇佣花费）
};
// 自定义普通函数：按Employee的skill升序排序，默认排序不知道用Employee的什么属性排序。
bool compareBySkill(Employee a, Employee b) {
    return a.skill < b.skill;  // 按技能升序排列
}

int main() {
    vector<int> tasks = {3, 7, 9};
    vector<Employee> employees = {
        {5, 10},
        {8, 20},
        {10, 15},
        {7, 18}
    };

    // 初始化排序升序
    sort(tasks.begin(), tasks.end());
    sort(employees.begin(), employees.end(), compareBySkill);//自定义排序方式
    int totalCost = 0;//总成本
    set<int> used; // 标记已使用的员工

    for (int task : tasks) {
        int minCost = 1e9;//当前任务的最小成本，初始为无穷大10的9次方
        int chosen = -1;//初始化员工下标-1表示没有目标员工

        //通过binary_search，来判断是否完全存在满足条件的员工
        // 先取出所有员工的技能用于查找
        vector<int> skills;//定义个skills动态数组
        for (auto &e : employees)
            skills.push_back(e.skill);
        // binary_search 判断是否有完全匹配的技能
        bool found = binary_search(skills.begin(), skills.end(), task);
        //这里可以增加if(found==true)-else，用于cout:found是否找到还是未找到
        // 上面这部分其实多余.因为下文skill>=task已经满足

        // 真正实施贪心逻辑代码从这里开始
        //通过循环找到最便宜的员工，当前无任务
        for (int i = 0; i < employees.size(); i++) {
            if (used.count(i)) continue;           // 判断当前员工是否已用，跳过
            if (employees[i].skill >= task) {      // 找到一个员工的技能能完成任务
                if (employees[i].cost < minCost) { // 继续判断，找成本更便宜的
                    minCost = employees[i].cost; //找到后，一直替换，直到成本更低员工
                    chosen = i;//同上，员工下标一直替换
                }
            }
        }
        //上面贪心找了一圈如果没有找到，直接返回失败
        if (chosen == -1) {
            cout << "❌ 无法完成所有任务" << endl;
            return 0;
        }
       //插入数据和计算成本
        used.insert(chosen);//将这个性价比的员工添加到
        totalCost += employees[chosen].cost;//将这个员工的薪资计入总成本中
        //继续tasks++，执行下一次循环
    }

    cout << "✅ 完成所有任务的最小总成本为: " << totalCost << endl;
    return 0;
}


```