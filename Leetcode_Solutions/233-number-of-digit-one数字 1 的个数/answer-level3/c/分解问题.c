### 解题思路
这种问题一般来说都是要寻找规律的，为了寻找规律可以写一个暴力模拟来计算

### 代码
```c
long long data[]={0,1,20,300,4000,50000,600000,7000000,80000000,900000000,10000000000};
long long power[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

long long f(long long n,long long sum)
{   if(n==0) return 0;
    if(n/power[sum]>1) return power[sum]+data[sum-1]*(n/power[sum])+f(n%power[sum],sum-1);
    if(n/power[sum]==1) return n%power[sum]+1+data[sum-1]+f(n%power[sum],sum-1);
    return f(n%power[sum],sum-1);
}

int countDigitOne(int n){
    if(n<=0) return 0;
    long long sum=0,p=n,count=0;
    while(p>0) p/=10,sum++;
    return f(n,sum);
}
```