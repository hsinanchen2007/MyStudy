### 解题思路
![Snipaste_2020-03-19_14-46-57.png](https://pic.leetcode-cn.com/573e7b61874790936994bc4c71bdbb7c03d07b7030d18bbaf81aec99b27e68cb-Snipaste_2020-03-19_14-46-57.png)
跟斐波那契一样迭代求就行。

### 代码

```c
int tribonacci(int n){
    if(n==0) return 0;
    if(n==1||n==2) return 1;
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    int i;
    for(i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    
    return dp[n];
}
```