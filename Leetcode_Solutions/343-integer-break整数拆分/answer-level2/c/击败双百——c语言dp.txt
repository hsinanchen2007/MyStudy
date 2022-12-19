### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/b885ca2d9dde079445b84dfb518a5a93fa6ca05aa239ee9e6b485d71a00265a5-%E6%8D%95%E8%8E%B7.PNG)
dp[i] = max(dp[i],max(dp[j],j)(i-j));
其含义是从1到i去找那个不比1和i乘积小的一对数，例如当j是5的话，max(dp[j],j)
就是取dp[5]（2乘3）而不取5 (1乘5) 取到最大的数再乘上剩余的数(i-5)即可。

如果还是不理解的，多写写，多画画，毕竟dp这种东西要亲手试验才理解的

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