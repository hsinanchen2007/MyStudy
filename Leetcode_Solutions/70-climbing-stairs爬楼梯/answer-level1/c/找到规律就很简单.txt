```
int climbStairs(int n){
    int a1=1,a2=2,a=0,*an=&a;
    if(n==a1||n==a2) return n;
    for(int i=3;i<=n;i++)
    {
        *an=a1+a2;
        a1=a2;
        a2=*an;
    }
    return *an;
}
```
