### 解题思路
仔细分析发现这就是一个数列问题。

### 代码

```c
int climbStairs(int n){
    /*if(n==1) return 1;
    if(n==2) return 2;
    return climbStairs(n-1)+climbStairs(n-2);*/
    if(n==1) return 1;
    if(n==2) return 2;
    int f1=1,f2=2,f=0;
    n=n-2;
    while(n>0){
        f=f1+f2;//3
        f1=f2;//2
        f2=f;//3
        n--;
    }
    return f;

}




```