### 解题思路
，分别计算0--N-2 （打劫了第一个房间，就不能打劫最后一间）；1--N-1（打劫最后一间房间，就不能弄第一间）；
最后取两次最大值

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int nsize=nums.size();
        if(nsize==0) return 0;
     
        if(nsize==1) return nums[0];
        if(nsize==2) return max(nums[0],nums[1]);
        
        vector<int> dp(nums.size(),0);
        /*计算 0-n-2*/
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<nsize;i++){
            dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }
        int ans=dp[nsize-2];
        /*计算 1-- n-1*/
        dp[1] = nums[1];    
        dp[2] = max(nums[1], nums[2]);
        for(int i=3;i<nsize;i++){
            dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }
        return max(ans,dp[nsize-1]);
    }
};
```