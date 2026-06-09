### 解题思路
排序后是一个最长递增子序列问题,很简单，用动态规划就能解决

### 代码

```cpp
class Solution {
public:
    //dp[i]表示以第i个元素结尾的最长递增序列
    int dp[10010];
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        fill(dp,dp+500,1);
        int max_len=0;
        //此时变成了最长递增子序列的问题
        for(int i=0;i<envelopes.size();i++){
            for(int j=0;j<i;j++){
                //后一个条件是因为尺寸相等的信封是不能互相装入的
                if(envelopes[j][1]<envelopes[i][1]&&envelopes[j][0]!=envelopes[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            if(dp[i]>max_len) max_len=dp[i];
        }
        return max_len;
    }
};
```