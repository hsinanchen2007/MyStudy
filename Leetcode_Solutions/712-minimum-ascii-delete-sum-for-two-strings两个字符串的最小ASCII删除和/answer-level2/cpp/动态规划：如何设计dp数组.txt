1. dp[i][j]代表的含义很重要,会影响状态转移方程的设计。
2. 设计dp数组的维度，可按情况增添行列，以防处理边界情况。
```
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len_1 = s1.size();
        int len_2 = s2.size();
        int dp[len_1+1][len_2+1];
        memset(dp, 0, sizeof(dp));
        dp[len_1][len_2] = 0;
        // 与其处理边界，不如增添一行一列作为辅助
        for(int i = len_1-1; i>= 0; --i)
        {
            dp[i][len_2] = int(s1[i]) + dp[i+1][len_2];
        }
        for(int j = len_2-1; j >= 0; --j)
        {
            dp[len_1][j] = int(s2[j]) + dp[len_1][j+1];
        }
        for(int i = len_1-1; i >= 0; --i)
            for(int j = len_2-1; j >=0 ; --j)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else 
                {   
                    dp[i][j] = min(int(s1[i])+dp[i+1][j], int(s2[j])+dp[i][j+1]);
                }
            } 
        return dp[0][0];
    }
};
```
![屏幕快照 2020-02-24 上午9.24.51.png](https://pic.leetcode-cn.com/3eaaae4c4ba78a175173b3f3628667c09e097542e6aae65496de3e5a74bb9dd1-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-24%20%E4%B8%8A%E5%8D%889.24.51.png)
