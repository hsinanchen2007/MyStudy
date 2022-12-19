### 解题思路
1. 定义dp数组,dp[i]标识以A[i]结尾的符合条件的子数组个数,那么可以分三种情况讨论
-  A[i]在L和R之间,那么dp[i]的值为i-rpos,其中rpos是i之前第一个大于R的元素位置
-  A[i]小于L,dp[i] = dp[i-1],如果i为0则dp[i]等于0.
-  A[i]大于R,则dp[i] = 0.
将所有dp[i]加和就是要返回的结果.
### 代码

```cpp
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int rpos = -1, result = 0;
        vector<int> dp(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) {
                dp[i] = 0;
                rpos = i;
            } else if (A[i] < L) {
                if (!i) dp[i] = 0;
                else dp[i] = dp[i-1];
            } else {
                dp[i] = i - rpos;
            }
            result += dp[i];
        }
        return result;
    }
};
```