第一次跳走 1 步
第二次可以走  1 2  步
第三次可以走 1 2 3 步
...
第n次可以走 1 2 3 ... n步

所以我们用unordered_map 存储   stone[i] - > i
枚举每一个位置就可以了```
代码块
```
```int dp[1500][1500];
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]>1) return false; 
        int n = stones.size();
        //set<int> s(stones.begin(), stones.end());
        unordered_map<int, int> m;
        for(int i=1;i<n;i++) m[stones[i]] = i;
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        for(int i=2;i<n;i++) {
            for(int k=1;k<=i;k++) {
                int j = m[stones[i]-k];
                if(dp[j][k-1]==1) {
                    dp[i][k] = 1;
                }
                if(dp[j][k]==1) {
                    dp[i][k] = 1;
                }
                if(dp[j][k+1]==1) {
                    dp[i][k] = 1;
                }
            }
        }
        for(int k=1;k<=n;k++) if(dp[n-1][k]) return true;
        return false;
    }
};

