### 解题思路
此处撰写解题思路
dp[i] 为当前0-i买的最小值
dp2[i]为当前i-n 卖的最大值。
然后你枚举i天就行。。
动态规划的思想。（当然你可以叫他打表emm）

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int siz=prices.size();
        if(!siz)return siz;
        int dp[siz];
        int dp2[siz];
        dp[0]=prices[0];
        for(int i=1;i<siz;i++){
            dp[i]=min(dp[i-1],prices[i]);
        } 
        dp2[siz-1]=prices[siz-1];
        for(int i=siz-2;i>=0;i--){
             dp2[i]=max(dp2[i+1],prices[i]);
        }
        int ans=-1;
        for(int i=0;i<siz;i++){
          ans=max(dp2[i]-dp[i],ans);
        }
        return ans;

    }
};
```