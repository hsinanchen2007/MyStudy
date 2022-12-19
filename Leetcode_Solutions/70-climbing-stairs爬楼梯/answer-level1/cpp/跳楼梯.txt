### 解题思路
此处撰写解题思路

递推式 r[i] = r[i-1] + r[i-2]
跳到第i层楼梯， 可以从第 i-1 层跳 1 个台阶，也可以从 i-2 跳2个台阶
r[i-1] 和 r[i-2] 的结果不需要保留，所以直接用 n1 表示 r[i-1], n2 表示 r[i-2]


### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n==1)
            return 1;

        auto n1 = 1;
        auto n2 = 1;
        auto r = 0;

        for (int i=2; i<=n; ++i) {
            r = n1+n2;
            n2 = n1;
            n1 = r;
        }

        return r;
    }
};
```