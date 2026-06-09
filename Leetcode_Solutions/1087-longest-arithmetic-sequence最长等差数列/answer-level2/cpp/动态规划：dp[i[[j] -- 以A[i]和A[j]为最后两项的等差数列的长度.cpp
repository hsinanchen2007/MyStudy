状态：
    dp[i[[j] -- 以A[i]和A[j]为最后两项的等差数列的长度
状态转移方程：
    dp[i[[j] = dp[k][i] + 1
    其中 A[j] - A[i] = A[i] - A[k] && k < i
注意点：
    如何处理重复出现的数字 （此处我用了一个递增的vector<int>来存储同数值的下标,感觉还可以更简化）
```
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int len = A.size();
        if(len <= 2) return len;

        map<int,vector<int>> vals;
        for(int i = 0; i < len; i++)
        {
            if(vals.find(A[i]) == vals.end()) vals[A[i]] = vector<int>(1, i);
            else vals[A[i]].push_back(i);
        }
        
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        int re = 2;
        for(int i = 0; i < len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if( vals.count(A[i]- (A[j]-A[i])) != 0)
                {
                    if(A[j]-A[i] == 0)
                    {
                        dp[i][j] = vals[0].size();
                        re = max(re, dp[i][j]);
                        continue;
                    }
                    for(auto it=vals[A[i] - (A[j]-A[i])].rbegin(); it != vals[A[i] - (A[j]-A[i])].rend(); it++)
                    {
                        if(*it < i)
                        {
                            dp[i][j] = dp[*it][i]+1;
                            re = max(re, dp[i][j]+2);
                            break;
                        }       
                    }   
                }
            }
        }
        return re;
    }
};
```
![屏幕快照 2020-03-15 上午11.41.01.png](https://pic.leetcode-cn.com/6264969e35e075c5a5392eec64e25047a248996800361570ca3fcc0cb9c2a8eb-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-15%20%E4%B8%8A%E5%8D%8811.41.01.png)
