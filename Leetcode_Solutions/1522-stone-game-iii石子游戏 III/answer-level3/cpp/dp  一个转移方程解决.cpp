### 动态规划
#### 状态
从stoneValue数组的末端开始，设`dp[i]`为从下标i处开始抉择到末尾所能得到的最大分数差，则`dp[i+1]`表示下标i+1处能得到的最大分数差。

我们假设在i处为Alice选择，则共有3种决策：
- 如果在i处选择只拿1堆，则i处Alice所得到的分数差为：拿了一堆得到的分数stoneValue[i]加上i+1处Alice的分数再减去i+1处Bob的分数。由于Bob是最优决策，i+1处Bob的分数减Alice的分数取最大，故i处Alice所得到的分数差为stoneValue[i]减去i+1处Bob所能拿到的最大分数差
即`Score1 = stoneValue[i] - dp[i+1]`
- 同理，Alice在i处拿2堆，有`Score2 = stoneValue[i] + stoneValue[i+1] - dp[i+2]`
- Alice在i处拿3堆，有`Score3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]`

三者取最大值即为i处Alice所能得到的最大分数差

于是得到**状态转移方程**：
`dp[i] = max(stoneValue[i] - dp[i+1], max(stoneValue[i]+stoneValue[i+1]-dp[i+2], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]));`
则dp[0]即为在下标0处开始抉择所能得到的最大分数差，若其>0，则说明最终Alice的分数>Bob的分数

为了方便，在dp数组后面加3个0，同时在stoneValue后面加2个0，这样在计算dp[n-1]、dp[n-2]时也有3种决策。
**初始条件**为没有石头堆，此时分数差为0，即`dp[n] = dp[n+1] = dp[n+2] = 0`

代码如下：
```
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        stoneValue.push_back(0);
        stoneValue.push_back(0);
        vector<int> dp(n+3);
        for (int i = n - 1; i >= 0; i--)
            dp[i] = max(stoneValue[i] - dp[i+1], max(stoneValue[i]+stoneValue[i+1]-dp[i+2], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]));
        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
};
```
时间复杂度为$O(n)$，空间复杂度为$O(n)$