### 解题思路
开始直接递归发现超时；
但是在结果看到规律是斐波那契
用递归实现斐波那契还是超时
最后选择直接用循环直接求出斐波那契

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1,f2 = 1,f3 = 0;
    if(n == 1)
    {
        return 1;
    }
    else
    {
        for(int i = 1; i < n; ++i)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
    }
    return f3;
    }
};
```