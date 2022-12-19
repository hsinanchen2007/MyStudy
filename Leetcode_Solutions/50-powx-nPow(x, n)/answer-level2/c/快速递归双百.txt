### 解题思路
快速幂运算
![a8773912b31bb0510b6490ff377adab44bede0a1.png](https://pic.leetcode-cn.com/8f426cec5adc5fc87f4b63212feb762d98a97bcdf04c53eb967022d3f15cafac-a8773912b31bb0510b6490ff377adab44bede0a1.png)
基于上述公式，递归求幂
### 代码

```c
double myPow(double x, int n)
{
    long long b = n;//int型负数取反时会溢出
    if(b==0)
    return 1;
    if(b<0)
    {
        x = 1/x;
        b = b*(-1);
    }
    if(b==1)
    return x;
    if(b%2==0)
    {
        return myPow(x*x,b/2);
    }
    else
    return x*myPow(x*x,b/2);
}
```