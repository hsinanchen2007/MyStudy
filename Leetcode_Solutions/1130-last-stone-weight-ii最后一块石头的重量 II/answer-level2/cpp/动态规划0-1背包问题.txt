### 解题思路
刚开始以为是一个最小堆的问题，利用贪心算法去解决，发现有的测试用例[33,31,25,24,10]搞不定,暂时没有想到比较好的贪心算法去解决问题。
看了大家的提出的将问题转换成n个数，上限位W/2，求最大重量的一个0-1背包问题，确实眼前一亮。
不同于解答区普遍的二维数组的方式，这边采用传统的0-1背包问题的解决方式：将容积V抽象成W/2，然后利用状态转移方程dp[i][j] = max(dp[i-1][j-W] + W[i], dp[i-1][j])，对我而言，记住这个公式解0-1背包问题会简单一些。

### 代码

```cpp
class Solution {
public:
int lastStoneWeightII(vector<int>& stones)
    {
        int totalStone = 0;
        for (auto stone : stones) {
            totalStone += stone;
        }
        vector<vector<int>> dp(stones.size() + 1, vector<int>(totalStone / 2 + 1, 0));
        for (int i = 1; i < stones.size() + 1; i++) {
            for (int j = 1; j <= totalStone / 2; j++) {
                if (j - stones[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j - stones[i - 1]] + stones[i - 1], dp[i - 1][j]);
                }
            }
        }
        return totalStone - (2 * dp[stones.size()][totalStone / 2]);
    }
};
```