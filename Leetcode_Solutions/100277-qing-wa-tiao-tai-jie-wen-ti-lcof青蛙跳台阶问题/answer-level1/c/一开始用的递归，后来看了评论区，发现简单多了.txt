### 解题思路
找规律，类似斐波那契数列
### 代码

```c
int numWays(int n){
    int i,m,q=1,ans=1;
    if(n==0) ans=1;
    if(n==1) ans=1;
    for(i=2;i<=n;i++){
        m=ans;
        ans=(ans+q)%1000000007;
        q=m;
    }
    return ans;
}
```