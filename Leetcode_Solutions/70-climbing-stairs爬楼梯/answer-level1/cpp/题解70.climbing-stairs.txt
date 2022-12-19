### 解题思路
斐波那契数列的应用，源自递归；注意每次f1 f2的更新应该是先更新f1，再f2。
// 基本情况：找最近子重复问题
// if else
// for while
// recursion（递归）
// 不断找重复
// 1: 1
// 2: 2
// 3: 3 ＝ f(1) + f(2) 可以先按第一级走法再走第二级，也可以先走2再走1，最后一步不一样，不会重复
// 4: 从n-2跨上来要两步，从n-1跨上来要一步：f(2) + f(3)
// n: 
// n只能从n-1或n-2级台阶走上来 f(n) = f(n-1) + f(n-2)

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1, f2 = 2, f3 = 3;
        if (n <= 2) return n;
        for (int i = 3; i < n + 1; i++) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};
```