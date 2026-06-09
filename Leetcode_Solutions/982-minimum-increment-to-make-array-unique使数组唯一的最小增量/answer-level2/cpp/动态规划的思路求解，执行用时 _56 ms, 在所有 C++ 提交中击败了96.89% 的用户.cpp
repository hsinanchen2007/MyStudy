
思路比较简单，执行速度快
```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int dp[40050];
        memset(dp,0,sizeof(dp));
        int re=0;
        int m=0;
        for(auto val:A)
        {
            m=max(m,val);
            dp[val]++;
        }
        for(int i=1;i<=m+1;++i)
        {
            re+=max(dp[i-1]-1,0);   //每一步需要递增max(dp[i-1]-1,0)个数字
            dp[i]+=max(dp[i-1]-1,0);    //将递增的数量加入增长后的数值的计数中
        }
        re+=max(dp[m+1]-1,0)*(dp[m+1])/2;   //将剩余的dp[m+1]个数字所需次数算入
        return re;
    }
};
```
