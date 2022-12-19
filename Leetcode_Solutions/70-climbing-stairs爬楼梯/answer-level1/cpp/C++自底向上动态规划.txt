### 解题思路
此处撰写解题思路
n = 1, f(1) = 1
n = 2, f(2) = 2
f(n) = f(n-1) + f(n-2)  这是递推公式
### 代码

```cpp
class Solution {
    /* n=1  f(1) = 1
       n=2  f(2) = 2
       n=3  f(3) = f(1) + f(2)
    */
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        int f1 = 1; int f2 = 2; int f3 = 0;
        for (int i=2; i<n; i++)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};
```