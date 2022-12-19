### 解题思路
dp[n]表示数为n时的最大划分整数乘积和
状态转移方程为：
dp[i] = max(dp[i],max(dp[j],j)*(i-j));
其含义是从1到i去找那个不比1和i乘积小的一对数，例如当j是5的话，max(dp[j],j)
就是取dp[5](2*3) 而不取5(1*5) 取到最大的数再乘上剩余的数(i-5)即可。
不是很理解的话多动手写写就明白了，毕竟dp这种东西最好自己动手试一下画一下
### 代码

```c
int max(int a,int b){
    return a>b?a:b;
}
int integerBreak(int n){
    int dp[60];
    memset(dp,0,sizeof(dp));
    int i,j;
    dp[1] = 1;
    for(i = 2; i <= n; i++){
        for(j = 1; j < i; j++){
            dp[i] = max(dp[i],(i-j)*max(dp[j],j));
        }
    }
    return dp[n];
}
```