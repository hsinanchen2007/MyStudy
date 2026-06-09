最长公共子数组模板题目, 参考了官方解答的以开头作为dp，以前的解法都是以结尾作为dp。

```
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        if (sizeA == 0 || sizeB == 0) {
            return 0;
        }
        vector<vector<int>> dp = vector<vector<int>>();
        for (int i=0; i<=sizeB; i++) {
            dp.emplace_back(vector<int>(sizeB+1, 0));
        }
        int res = 0;
        for (int i=sizeA-1; i>=0; i--) {
            for (int j=sizeB-1; j>=0; j--) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                    res = max(dp[i][j], res);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};
```