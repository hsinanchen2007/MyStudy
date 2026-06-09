### 解题思路
要求最少删几列，反过来就是最长剩几列。我们可以定义两列之间的大小关系：如果每一行的元素都满足同样的大小关系，这两列之间就满足这一大小关系。这样，我们就把每列变成了一个元素，从而原题就变成了最经典的最长不下降子序列问题。

最后，记得返回时用n减掉求得的最长序列长度。

### 代码

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A[0].size();
        vector<int> dp(n + 1, 1);
        int ans = 0;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j < i; ++j) {
                bool ok = true;
                for (int k = 0; k < A.size(); ++k) {
                    if (A[k][i - 1] < A[k][j - 1]) {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        return n - ans;
    }
};
```