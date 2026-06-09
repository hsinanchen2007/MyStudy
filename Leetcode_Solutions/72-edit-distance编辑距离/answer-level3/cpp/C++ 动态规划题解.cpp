```
class Solution {
public:
    int min3(int x, int y, int z) {
        return min(min(x, y), z);
    }
    int minDistance(string word1, string word2) {
        int R = word1.size();
        int C = word2.size();
        int dp[R + 1][C + 1] = {0};
        for (int i = 0; i <= R; ++i) dp[i][0] = i;
        for (int i = 0; i <= C; ++i) dp[0][i] = i;
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                dp[i][j] = min3(
                    dp[i - 1][j] + 1, 
                    dp[i][j - 1] + 1, 
                    dp[i - 1][j - 1] + int(word1[i - 1] != word2[j - 1]));
            }
        }
        return dp[R][C];
    }
};
```

![image.png](https://pic.leetcode-cn.com/6ab97b100e8d571838f356dd66ff5a2ae71554bc4732c80fedfd73e68de39e22-image.png)
