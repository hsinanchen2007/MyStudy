### 解题思路
定义dp[i][j]标识分别以A[i]和B[j]结尾的最长相等子数组长度
如果A[i] != B[j] 则dp[i][j] = 0;
如果A[i] == B[j] 则dp[i][j] = dp[i-1][j-1] + 1;

由于dp[i][j]只与上一行的dp[i-1][j-1]相关，因此，从后向前迭代j时，可以将二维数组简化到1维

### 代码

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> dp(B.size()+1, 0);
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = B.size()-1; j >= 0; --j) {
                dp[j+1] = A[i] == B[j] ? dp[j] + 1 : 0;
                result = max(result, dp[j+1]);
            }
        }
        return result;
    }
};
```