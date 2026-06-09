### 解题思路
斐波那契非递归模板

### 代码

```c
int numWays(int n){

    int n_1=1,n_2=1,ans=1;
    for(int i=2;i<=n;++i)
    {
        ans=(n_1+n_2)%1000000007;
        n_2=n_1;
        n_1=ans;
    }
    return ans;
}
```