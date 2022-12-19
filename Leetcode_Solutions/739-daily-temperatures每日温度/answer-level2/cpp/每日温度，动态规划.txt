### 解题思路
对于第i天，dp[i]记录下一个比i大的数的偏移值，即nums[i] < nums[i+dp[i]]
那么记k=i+1，我们比较nums[i]和nums[k]，若nums[i] < nums[k]，则dp[i]=k-i，
若nums[i] >= nums[k]，那么我们继续往后遍历，找到下一个比nums[k]大的值，即k += dp[k]
若dp[k]==0，说明再也没有比nums[k]大的数了，若此时仍小于nums[i]，那么dp[i]=0
### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> dp(T.size(),0);
        for(int i = T.size()-2;i>=0;--i){
            int k = i+1;
            while(k < T.size()){
                if(T[i] < T[k]){
                    dp[i] = k-i;
                    break;
                }
                else{
                    if(dp[k] == 0)
                        break;
                    k += dp[k];
                }
            }
        }
        return dp;
    }
};
```