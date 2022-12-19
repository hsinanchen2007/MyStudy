### 解题思路
官方算法的复现。
笔记：
1. 用long long代替int防止越界
2. 开始时就判断n的正负可以节约开支
3. 利用递归很简洁。改写成迭代也不复杂
### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long a = n;
        if (a < 0) {
            x = 1/x;
            a = -a;
        }
        return myPow_core(x, a);
    }
    double myPow_core(double x, long long a) {
        if (x == 1 || a == 0)
            return 1;
        double pow_re = myPow_core(x, a/2);
        if (a%2 == 0)
            return pow_re * pow_re;
        else
            return pow_re * pow_re * x;
    }
};
```