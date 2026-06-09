### 解题思路
不要递归，注意取模

### 代码

```c
int fib(int n){
    int n_1,n_2=0,ans=1;
    if(n==0) ans=0;
    if(n==1) ans=1;
    for(int i=2;i<=n;i++){
        n_2=n_1;
        n_1=ans;
        ans=(ans+m)%1000000007;
    }
    return ans;
}
```