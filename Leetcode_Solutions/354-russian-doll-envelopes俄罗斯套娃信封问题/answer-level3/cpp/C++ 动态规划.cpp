### 解题思路
注意 dp 数组初始值为1
更新公式：dp[i] = max(dp[i], dp[j]+1);
用 maxE = max(dp[i], maxE); 记录最多套娃数

### 代码

```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        if(n<=1) return n;
        vector<int> dp(n, 1);
        int maxE = 1;
        for(int j=0; j<n; j++){
            for(int i=j+1; i<n; i++){
               if(envelopes[i][1]>envelopes[j][1] && envelopes[i][0]>envelopes[j][0]){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxE = max(dp[i], maxE);
                }
            }
        }
        return maxE;
    }
};
```