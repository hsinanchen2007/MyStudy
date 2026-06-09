**解题思路**

**关于动态规划的编程问题，基本都遵循一个固定的套路**：
1. 根据题目条件找规律推导状态转移方程
2. 设定递推基

**代码如下：**
```
int change(int amount, int* coins, int coinsSize){
    int dp[amount+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0;i<coinsSize;i++){
        int coin = coins[i];
        for(int j=1;j<=amount;j++){
            if(j<coin) continue;
            dp[j] += dp[j-coin]; 
        }
    }
    return dp[amount];
}
```
**复杂度分析**

时间复杂度：O(M*N) 其中M为amount，N为coins数组的长度
空间复杂度：O(M) dp数组使用的空间

![567937de70ddd82d644b77ac7019412.png](https://pic.leetcode-cn.com/be4695e6a33b4b70bd2427a3d3754aef9c1481f365211ac29fc7a8bcd42200e8-567937de70ddd82d644b77ac7019412.png)

