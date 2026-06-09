```C++
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z);
#ifdef RECURSIVE
    bool canMeasureWater(int x, int y, int z, set<pair<int, int>> &visited, int a, int b);
#endif
};

#ifdef RECURSIVE
// 能够想到使用暴力枚举，利用递归求解，是比较常规的思路，一些解题中的数学方法真的是蛮难想到
// 最开始可以判断，x+y<z则不能凑齐，因为只能用两个瓶子
// 这里先尝试DFS暴力递归，需要明确递归的终止条件
// 先把x和y看成当前两个瓶子中分别还有的水量
// x==z或者y==z或者z+y==z则直接返回true，说明凑到了
// 剩下的情况进行递归处理，因为可能由于若干次的加水倒数或者互相倒水，导致两个瓶子的水量和之前某一次搜索时的情况完全相同
// 这种情况下无需再处理，否则导致死循环，设置一个set用于存放可以已经搜索过的情况
// 每次递归时，判断当前情况是否已经考虑过，考虑过则直接return，否则继续递归
// 若不存在这样的组合，则set中最终会枚举到所有的情况，不会导致无限递归
// 如果存在，则在某一次会return true，其他情况则会最终返回

// 慎用unordered容器

// 判断当前水量是否满足条件，否则递归判断，首先需要判断当前情况是否是此前搜索过的情况，并且visited中的组合必然是不满足条件的
// 如果满足条件则直接return true，并且不加入到visited集合中

bool Solution::canMeasureWater(int x, int y, int z, set<pair<int, int>> &visited, int a, int b) {
    auto p = make_pair(x, y);
    if (visited.count(p))
        return false;
    if (x == z || y == z || (x + y) == z)
        return true;
    visited.insert(p);
    // 递归以下的几种情况
    bool ret = canMeasureWater(x, 0, z, visited, a, b) || canMeasureWater(0, y, z, visited, a, b) ||
               canMeasureWater(x, b, z, visited, a, b) || canMeasureWater(a, y, z, visited, a, b) ||
               canMeasureWater(x-min(x,b-y), y+min(x,b-y), z, visited, a, b) || 
               canMeasureWater(x+min(y,a-x), y-min(y,a-x), z, visited, a, b);
    return ret;
}

bool Solution::canMeasureWater(int x, int y, int z) {
    if (x + y < z)
        return false;
    set<pair<int, int>> visited;
    return canMeasureWater(0, 0, z, visited, x, y);
}

// 本地运行可以，然而，Leetcode上爆栈了，不能写递归形式，那只能写手动模拟递归形式的bfs或者dfs
#elif defined NON_RECURSIVE
// 手动写DFS吧，利用一个栈，仍然需要set结构存放不满足的已搜索过的组合
bool Solution::canMeasureWater(int x, int y, int z) {
    if (x + y < z)
        return false;
    stack<pair<int, int>> stk; stk.push({0,0});
    set<pair<int, int>> visited;
    while (!stk.empty()) {
        auto p = stk.top(); stk.pop();
        if (visited.count(p))
            continue;
        if (p.first == z || p.second == z || p.first+p.second == z)
            return true;
        // 本次情况(x,y)已经搜索过，不满足条件，因此加入到visited中，避免下一次重复搜索
        visited.insert(p);
        // 将6种情况入栈，模拟下一次的函数调用
        stk.push({p.first,0}); stk.push({0,p.second}); // 倒空其中一个（两个都倒空的情况会在下一次递归过程中搜索到，因此不用考虑）
        stk.push({p.first,y}); stk.push({x,p.second}); // 倒满其中一个
        stk.push({p.first-min(p.first,y-p.second), p.second+min(p.first,y-p.second)}); // X往Y里倒
        stk.push({p.first+min(p.second,x-p.first), p.second-min(p.second,x-p.first)}); // Y往X里倒
    }
    return false;
}
// 嗯，通过了，然而。。执行用时2280ms，内存216.5MB，吓死了。。。
#else
// 还是贝尔定理好
int gcd(int x, int y) {
    if (x < y) return gcd(y,x);
    if (y==0) return x;
    return gcd(x % y, y);
}

bool Solution::canMeasureWater(int x, int y, int z) {
    if (x + y < z)
        return false;
    // 坑爹的边界情况（xy中至少一个为0的三种情况）
    if (x == 0 || y == 0) return z == 0 || x + y == z;
    return !(z % gcd(x,y));
}
#endif
```
