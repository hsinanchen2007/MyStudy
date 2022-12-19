
```c++ []
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int len = A.size();
        int result = 1;
        vector<unordered_map<int,int>> dp(len);
        for(int i = 0; i < len; i++)
            for(int j = 0; j < i; j++)
            {
                int key = A[i] - A[j];
                if(dp[j][key] != 0) dp[i][key] = dp[j][key] + 1;
                else
                    dp[i][key] = 2;
                result = max(result, dp[i][key]);
            }
        return result;
    }
};
```

这里把每个数都建立一个hash表，每个hash表的存的是第dp[i],表示0-i所有可能的等差数列的长度，其中以公差作为键值   在代码中key就是公差。