### 解题思路
此处撰写解题思路
这道题很简单哦~
### 代码

```c
int fib(int n){
    int m,q=0,ans=1;
    if(n==0) ans=0;
    if(n==1) ans=1;
    for(int i=2;i<=n;i++){
        m=q;
        q=ans;
        ans=(ans+m)%1000000007;
    }
    return ans;
}
```