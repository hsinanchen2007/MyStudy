### 解题思路
此处撰写解题思路

### 代码

```c
double upow(double x, int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else if(n%2==0)
        return upow(x*x,n/2);
    else 
        return upow(x*x,n/2)*x;
}
double myPow(double x, int n)
{
    if(n>=0)
        return upow(x,n);
    else 
        return 1/upow(x,n);
}

```