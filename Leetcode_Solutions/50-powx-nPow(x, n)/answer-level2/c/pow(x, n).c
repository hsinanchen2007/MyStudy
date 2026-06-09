### 解题思路
此处撰写解题思路
1. 特殊情况幂为0或者底为1
2. 幂为1输出接口
3. 幂小于0，将幂转换为正整数递归
4. 幂大于0，将底平方，然后幂减半递归
### 代码

```c
double myPow(double x, int n)
{
    if (n == 0 || x == 1) return 1;
    else if (n == 1) return x;
    else if (n < 0) return 1 / myPow(x, -(n + 1)) / x;
    else if (n % 2 == 0) return myPow(x * x, n / 2);
    else return myPow(x * x, n / 2) * x;
}
```