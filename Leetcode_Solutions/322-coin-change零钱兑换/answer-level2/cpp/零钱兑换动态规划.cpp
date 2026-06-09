### 解题思路
设置变量dp[i]表示当前兑换了i个钱的状态
状态转移是有什么方案可以兑换到i这个数目的钱，即枚举coins数组
如果i-coins[j]>0，表示可以由状态i-coins[j] 到状态i ,然后我们到状态i的硬币数即是dp[i-coins[j]]+1，加的这个1就是使用coins[j]这个硬币从状态i-coins[j]到状态i。通过遍这个coins数组我们就可以找到硬币数最少的到状态i的状态然后更新状态i的dp值即dp[i]

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001];
        dp[0]=0;
        for(int i=1;i<=amount;i++){ //先初始化最大值，代表着这个状态下兑换不了零钱
            dp[i]=999999;
        }
        for(int i=1;i<=amount;i++){ //从第一个状态开始遍历每一个状态
            for(int j=0;j<coins.size();j++){ //对每一个状态遍历coins数组找到可到i的最小的状态
                if(i-coins[j]>=0 && dp[i-coins[j]]!=999999) dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]==999999?-1:dp[amount];
    }
};
```