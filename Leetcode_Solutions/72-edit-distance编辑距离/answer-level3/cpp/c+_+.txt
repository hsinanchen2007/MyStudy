### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.size(), w2 = word2.size();
        if(w2 == 0) return w1;
        if(w1 == 0) return w2;
        vector<char> wo1(w1+1);
        vector<char> wo2(w2+1);
        for(int i = 1;i <= w1;++i) wo1[i] = word1[i-1];
        for(int i = 1;i <= w2;++i) wo2[i] = word2[i-1];

        vector<vector<int>> dp(w1+1, vector<int>(w2+1, 0x3f3f3f));        

        for(int i = 0;i <= w1;++i) dp[i][0] = i;
        for(int i = 0;i <= w2;++i) dp[0][i] = i;

        for(int i = 1;i <= w1;++i)
            for(int j = 1;j <= w2;++j){
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);//删除和插入
                if(wo1[i] == wo2[j])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                else 
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            }

        return dp[w1][w2];
    }
};
```