# 思路：
1，先对数对进行排序，按照尾部数字进行从小到大排序
2，进行动态规划求解，`dp[i]`代表前`i`（从0开始计数）个数形成的最长数对数
状态转移方程
`dp[i] = max{dp[i - 1], 1 + dp[j]}` `j`为满足小于数对`i`且距离i最近的一个数对下标
```C++ []
class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[1] == v2[1]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int N = pairs.size();
        vector<int> dp(N, 0);
        dp[0] = 1;
        for (int i = 1; i < pairs.size(); ++i) {
            dp[i] = dp[i - 1];
            int j = i - 1;
            while (j >= 0 && pairs[j][1] >= pairs[i][0]) --j;
            if (j >= 0) dp[i] = max(dp[i], 1 + dp[j]);
        }
        return dp[N - 1];
    }
};
```

![image.png](https://pic.leetcode-cn.com/7263c4831f5b066498fabe37259876b69a59caf44780690651563129daf3c9f6-image.png)
