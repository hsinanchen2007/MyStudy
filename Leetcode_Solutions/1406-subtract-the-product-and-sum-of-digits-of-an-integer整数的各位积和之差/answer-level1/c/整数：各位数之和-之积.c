### 解题思路
加法、乘法有交换律，所以先从低位到高位和高位到低位都可以。

### 代码

```c
int subtractProductAndSum(int n){
    int sum=0,mul=1;
    while(n!=0)
    {
        int num=n%10;
        n/=10;
        sum+=num;
        mul*=num;
    }
    return mul-sum;
}
```