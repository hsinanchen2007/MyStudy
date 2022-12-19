### 解题思路
单纯的递归写法。
对于一个n完全树，其总数为 以  【1，n】每个值为根节点的数量进行求和。
 其中每个根节点 i (1<= i <= n) 来说， 其数量为
    左侧节点排列数f（i-1）* 右侧节点排列数 f（n-i）; 
  之所以用dp记录一下，就是因为如果纯递归会导致超时。
### 代码

```c
int numTrees(int n){
    int *dp = (int *)malloc(sizeof(int) * (n+1));
    memset(dp, 0, sizeof(int) * (n+1));
    if (n <= 1) {
        return 1;
    }
    dp[0] = 1;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1; j <= i; j++) {
            res += dp[i - j] * dp[j-1];
        }        
        dp[i] = res;
    }

    return dp[n];
}
```