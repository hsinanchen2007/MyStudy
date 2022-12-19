### 解题思路
参考前排大佬，跟剪绳子-I思路相同，只是对中间结果进行了范围限制。

### 代码

```c
int cuttingRope(int n){
    if(n<=3)
        return n-1;
    int a=n/3-1,b=n%3,p=1000000007;
    long long int sum=1;
    while(a>0)
    {
        sum=(sum*3)%p;
        a--;
    }
    if(b==0)
        sum=(sum*3)%p;
    else if(b==1)
        sum=(sum*4)%p;
    else
        sum=(sum*6)%p;
    return sum;
}
```