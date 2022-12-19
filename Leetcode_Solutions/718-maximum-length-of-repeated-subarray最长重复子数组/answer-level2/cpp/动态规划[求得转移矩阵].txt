### 解题思路
1、定义dp[i][j] 为A index = i  B index = j 结尾的对应最大公共长度。
2、求取其中的最大值；
3、返回

### 代码

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || A.size() == 0 || B.empty() || B.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        int maxCount = 0;
        for (int i = 1 ; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                maxCount = max(maxCount, dp[i][j]);
            }
        }
        return maxCount;
    }
};
```