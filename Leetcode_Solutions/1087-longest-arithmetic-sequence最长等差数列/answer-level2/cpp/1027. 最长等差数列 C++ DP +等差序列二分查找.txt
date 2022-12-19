### 解题思路
此题与基本是相同的，可以先学习下该题的做法
1）300. 最长上升子序列
https://leetcode-cn.com/problems/longest-increasing-subsequence/

因为是等差序列的最大值。因此
1）dp[i]表示第i个数的等差序列的最大值
2）dp[i][diff] 表示第i个数在差值为diff时等差序列的最大值
转移方程
1）dp[i] = max(dp[i][diff]) ,diff 是i对于0~i-1所有的数字差值，从其中取最大值；
2）dp[i][diff] = dp[j][diff]+1;
3）如果i计算的diff在j数字中不存在，则dp[i][diff] =2;

注意：提升效率，不要用map要用unordered_map


等差序列二分查找：
1）二层循环计算每个差值
2）依据差值向后遍历，如果找到，则继续，如果没有找到，则返回。




### 代码

```cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {

        if(A.empty()){
            return 0;
        }

        vector<unordered_map<int,int>> diffs = vector<unordered_map<int,int>>(A.size(),unordered_map<int,int>());
        vector<int> dp = vector<int>(A.size(), 2);
        int maxvalue = 0;
        dp[0] = 1;

        for (int i = 0; i < A.size();i++){
            for (int j = 0; j < i;j++){
                int diff = A[i] - A[j];
                if(diffs[j].count(diff)){
                    diffs[i][diff] = max(diffs[i][diff], diffs[j][diff] + 1);
                }else{
                    diffs[i][diff] = 2;
                }
                dp[i] = max(dp[i], diffs[i][diff]);
            }

            maxvalue = max(maxvalue, dp[i]);
        }

        return maxvalue;

    }
};

```