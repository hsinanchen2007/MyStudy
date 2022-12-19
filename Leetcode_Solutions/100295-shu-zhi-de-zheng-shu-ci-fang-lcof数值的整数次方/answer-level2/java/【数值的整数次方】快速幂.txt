### 题目描述

实现函数`double Power(double base, int exponent)`，求`base`的`exponent`次方。不得使用库函数，同时不需要考虑大数问题。


### 样例

样例 1:

```
输入: 2.00000, 10
输出: 1024.00000
```
样例 2:
```
输入: 2.10000, 3
输出: 9.26100
```
样例 3:
```
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
```

### 思路
看到是求一个数的整数次方$x^n$，那么很容易想到如下结论：
- `n`为偶数，则 $x^n=x^{n/2}*x^{n/2}$
- `n`为奇数，则 $x^n=x^{n/2}*x^{n/2}*x$ 
> 注：这里是整除，本来应该是$x^n=x^{(n-1)/2}*x^{(n-1)/2}*x$

基于上述，那么代码就很容易写了，递归和迭代都可以，以下给出迭代代码。

### 代码
```java
public double myPow(double x, int n) {
        double ans = 1, temp = x;
        int exp = n;
        while (exp != 0) {
            if ((exp % 2) != 0) {
                ans = ans * temp;
            }
            temp = temp * temp;
            exp /= 2;
        }
        return n > 0 ? ans : 1 / ans;
    }
}
```