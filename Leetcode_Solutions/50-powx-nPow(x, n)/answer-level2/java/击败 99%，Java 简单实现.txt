# 50. Pow(x, n) [题目链接](https://leetcode-cn.com/problems/powx-n/)

> 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

> 示例 1:
> 输入: 2.00000, 10 
> 输出: 1024.00000

思路分析：

-  x^n=  x^n/2 * x^n/2 —— n 为偶数时， x^n=  x^(n-1)/2 * x^(n+1)/2  —— n为奇数时
- 当 n 为 负数时，x^n= 1/(-x)^n
- 当 x 为正数时，x^n= x^n/2 * x^n/2
- x 为负数时，偶数次方为正数，奇数次方为负数

```java
class Solution {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        boolean flag = n < 0; // 判断 n 是否为负数
        if (n % 2 != 0) {
            return flag ? 1 / (myPow(x * x, -(n / 2)) * x) :
                    myPow(x * x, n / 2) * x;
        }
        return flag ? 1 / myPow(x * x, -(n / 2)) :
                myPow(x * x, n / 2);
    }
}
```
