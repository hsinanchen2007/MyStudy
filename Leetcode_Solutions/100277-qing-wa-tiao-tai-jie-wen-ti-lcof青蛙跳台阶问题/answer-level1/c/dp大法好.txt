### 解题思路
此处撰写解题思路

### 代码

```c
int numWays(int n){
/*    int ans=0;
    if(n==1){
        return 1;
    }
    else if(n==0){
        return 1;
    }
    else{
        ans=numWays(n-1)+numWays(n-2);//踏上第n层的方法就是踏上第n-1层加上第n-2层的方法
    }
    return ans%1000000007;
*/
//优化后：采用dp，上面的只能到43
//传递函数dp[i]=dp[i-1]+dp[i-2]
    int f1=1;
    int f2=1;
    int ans=1;
    for(int i=2;i<=n;i++){
        ans=f1+f2;
        f2=f1%1000000007;//注意这里，如果不优化下会到92
        f1=ans%1000000007;
    }
    return ans%1000000007;
}
```