

### 解题思路
这道题用排列组合，想必是会碰到溢出的
对于排列组合的公式C(x,y)=x!/(((x-y)!)(y!))
我们可以先计算x!除以(x-y)!和(y!)中较大的一个，然后即可有效防止溢出
时间复杂度为一次函数数量级
空间复杂度在不使用递归求阶乘的情况下可以是常数级
### 代码

```c
int uniquePaths(int m, int n){
    if(m!=1&&n!=1)
    return C_((m+n-2),(m-1)<(n-1)?(m-1):(n-1));
    else
    return 1;
}
int C_(int x,int y){//求组合数
    long Qs,Product=x;
    for(Qs=1;Qs<(y<(x-y)?y:(x-y));Qs++)
    {
        Product*=(x-Qs);
    }
    return Product/Factorial(y<(x-y)?y:(x-y));
}
int Factorial(int x){//求阶乘
    if(x<=1)
    return 1;
    else
    return x*Factorial(x-1);
}
```