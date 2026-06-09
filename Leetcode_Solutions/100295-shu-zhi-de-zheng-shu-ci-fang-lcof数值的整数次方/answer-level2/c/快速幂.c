### 解题思路
快速幂
### 代码

```c
double power(double x,long long n)
{
    double out=1;
    double tmp=x;
    while(n)
    {
        if(n&1==1)
        {
            out*=tmp;
        }
        n=n>>1;
        tmp*=tmp;
    }
    return out;

}

double myPow(double x, int n){
    if(x<1e-6&&x>-1e-6)
    {
        return 0;
    }
    // else if(x-1<1e-6&&x-1>-1e-6)
    // {
    //     return 1;
    // }

    else
    {
        if(n==0)
        {
            return 1;
        }
        else if(n<0)
        {
            x=1/x;
            return power(x,-(long long)n);
        }
        else
        {
            return power(x,n);
        }
    }

}

```