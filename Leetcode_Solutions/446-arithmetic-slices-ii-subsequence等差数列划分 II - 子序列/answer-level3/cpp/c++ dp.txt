### 解题思路
这个题目很容易想到需要用到二维dp数组，且第一维是数组下标，第二维是dlt
但是dp[i][dlt]存放什么数据，表达什么意思，不那么容易思考。

一开始错误的用dp[i][dlt]存放以A[i]结尾且等差是dlt的序列的长度，这样可以迭代i之前的每个j使dp[i][dlt] = dp[j][dlt]+1，再把所有dp[i][dlt]加和就可以得到结果。但问题是碰到有重复数据的情况，比如 10,10,9,8这种，就无法得出正确答案，因为对于9来说前面两个10的结果重叠在了一起。

如果dp[i][dlt]存放以A[i]结尾等差为dlt的序列的数量，又有长度为2的序列掺杂的统计结果中，如何排除长度为2的序列呢？

我们可以这么做，dp[i][dlt]还是存放以A[i]结尾等差为dlt的序列的数量，对每个i之前的j，dp[i][A[i]-A[j]]更新如下
dp[i][A[i]-A[j]] ++;                  // 多了(j, i)序列
dp[i][A[i]-A[j]] += dp[j][A[i]-A[j]];
但每次更新结果数量result时是将dp[j][A[i]-A[j]]的结果加到result中。
因为A[i]的存在，dp[j][A[i]-A[j]]中的所有序列 + A[i]的长度必然大于2；


### 代码

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<long long, int>> dp(A.size());
        long long result = 0;
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long long dlt = (long long)A[i] - (long long)A[j];
                dp[i][dlt] ++;
                if (dp[j].count(dlt)) {
                    result += dp[j][dlt];
                    dp[i][dlt] += dp[j][dlt];
                }
            }
        }
        return result;
    }
};
```