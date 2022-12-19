```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int N1 = word1.size();
        int N2 = word2.size();
        vector<vector<int> > dp(N1 + 1, vector<int>(N2 + 1));
        for (int i = 1; i <= N1; ++i) {
            for (int j = 1; j <= N2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return N1 + N2 - 2 * dp[N1][N2];
    }
};
```

![image.png](https://pic.leetcode-cn.com/f7116ec2bd96d45474d553455edcb650f1de6151853f65827a1b5638a446b9b5-image.png)
