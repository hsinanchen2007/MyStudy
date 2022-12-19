### 解题思路
见代码注释

### 代码

```c
double myPow(double x, int n){
    /*使用复杂度为O(logN)的递归算法pow(x,n)=pow(pow(x,n/2),2)*/
    if(n==0)
        return 1;
    if(x==0)
        return 0;
    //因为负数最小值比正数最大值绝对值大1，单独处理-2^31次方
    if (n == -2147483648)
    {
        return myPow(x, -2147483647) * (1/x);
    }
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }
    /*处理完特殊情况后，开始设定递归起始参数*/
    if(n==1)
        return x;
    double xn = myPow(x, n / 2);
    if(n%2==0)
    {
        return xn * xn;
    }

    return xn * xn * x;
}
```