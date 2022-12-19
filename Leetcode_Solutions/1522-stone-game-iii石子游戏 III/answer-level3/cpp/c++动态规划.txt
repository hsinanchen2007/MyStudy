动态规划，维护一个数组vector<pair<int, int>> dp，dp[i]表示在有后面i堆石子的情况下的状态，dp[i].first表示先手最佳得分，dp[i].second表示后手最佳得分。每次状态dp[i]只需要依靠更少石子堆的状态，复杂度为O(n)。最后根据dp[n]得到返回结果。
```cs
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<pair<int, int>> dp(1, make_pair(0, 0));
        int n = stoneValue.size();
        for (int i = 1; i <= n; i++) {  // 当有i堆石子，stoneValue[n-i, n-1]
            int maxV = -0x3f3f3f3f, maxP = -1, tot = 0;
            for (int j = 1; j <= 3 && j <= i; j++) {
                tot += stoneValue[n-i+j-1];
                if (maxV < tot+dp[i-j].second)
                    maxV = tot+dp[i-j].second, maxP = i-j;
            } 
            dp.push_back(make_pair(maxV, dp[maxP].first));
        }
        return dp[n].first == dp[n].second ? "Tie" : (dp[n].first < dp[n].second ? "Bob" : "Alice");
    }
};
```
