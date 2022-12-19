### 解题思路
这题和找硬币问题是一样的思路 [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)
![image.png](https://pic.leetcode-cn.com/50698696832451974e78636f1e6f385dfddcfc17245de40b8235b3b5366573e7-image.png)
解决这个问题，使用动态规划的套路

322.零钱兑换
**1）定义数组
2）赋初值
3）找状态转移方程式**

1）dp[n] 表示当钱数为n的时候零钱的数量
2）dp[0] = 0  当钱数为0的时候，一定不用找钱。
3）找出状态转移方程：当需要找的钱数为n的时候，我们可以考虑分别排除每种面值的硬币需要找多少钱，然后再加上一个被排除硬币的个数，即：
        dp[n] = min(dp[n],dp[n - coin]+1)
    循环遍历排除h各个面值的硬币，不断更新最小值，循环结束后，就是我们想要的结果：当钱数为n时，最少需要找dp[n]个硬币。
代码：
```
代码块
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins)
                if (coin <= i)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }

};
```

279 完全平方数：
根据解决动态规划问题主要为三个步骤：
1）定义数组
2）赋初值
3）找状态转移方程式

1）2）略

最关键的是如何找出动态转移方程式
在这题中，题目说找出若干个完全平方数使他们的和等于n
我们已经知道初值dp[0] = 0;
我们来看看dp[n] 如何来找：
    因为n最长可能由n个1构成，所以我们一开始就设dp[n] = n;
    然后从j = 1开始，让（n - j*j），这就找到了dp[n-j*j]（除掉完全平方数为j*j）的dp值， 然后再加上我们去掉的j*j（一个完全平方数）
    我们目的是找到最小的那个，所以，我们使用标准库中的min（），来不断更新dp[n]
即找到的状态转移方程为：
    dp[i] = min(dp[i],dp[i-j*j]+1)
最后贴上代码：

### 代码

```cpp
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1]; 
        dp[0] = 0;
        //自底向上，递推f[1] -> f[n] 之间的所有状态
        for(int i = 1; i <= n; ++i){
           
            dp[i] = i;
            //边界状态 j*j <= i
            for(int j = 1; j*j <= i; ++j){
               
                dp[i] = min(dp[i],dp[i-j*j]+1);
                
            }
        }
        return dp[n];    //返回数组f保存的状态值
    }
};
//时间复杂度O(n*log(n))

```