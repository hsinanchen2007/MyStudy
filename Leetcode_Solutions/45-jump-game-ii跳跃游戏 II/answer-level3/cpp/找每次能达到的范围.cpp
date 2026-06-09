### 解题思路
每次能达到的范围都是连续的，因此只需要记录某一次能到达的范围即可，知道推导到最后。
时间复杂度O(n)
转自：https://leetcode-cn.com/problems/jump-game-ii/solution/45-by-ikaruga/
### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int end=0,res=0,maxx=0;
        for(int i=0;i<nums.size()-1;i++){
            maxx=max(maxx,i+nums[i]);
            if(i==end){
                res++;
                end=maxx;
            }
        }
        return res;
        // vector<int> dp(nums.size(),0x7fffffff);
        // dp[0]=0;
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=1;j<=nums[i] && i+j<nums.size();j++){
        //         dp[i+j]=min(dp[i+j],dp[i]+1);
        //     }
        // }
        // return dp[nums.size()-1];
    }
};
大佬算法果然比summer的dp快一万倍
```