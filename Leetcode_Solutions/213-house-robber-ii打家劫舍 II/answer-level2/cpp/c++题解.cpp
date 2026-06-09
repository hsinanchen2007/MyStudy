和打劫家舍I 差不多，只是选择偷第一件房间时和第一问有所不同，不偷第一间房间则和 打劫家舍I问题完全重复，我们去两种选择获得的收益的最大值即可，以下是代码，仅供参考。时空复杂度O(n)
```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int *dp = new int[n];
        //如果房子数目小于等于三，至多能偷一个
        if(n<=3){
            int t = 0;
            for(int i= 0;i<n;i++){
                t = max(t,nums[i]);
            }
            return t;
        }
        //注：dp[i]的含义为：在i到n-1间房子（序号0...n）之间)进行偷盗能获得的最大收益dp[i]
        int answer= 0;
        //不偷第一件房子
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i = n-3;i>=1;i--){
            dp[i]=  max(nums[i]+dp[i+2],dp[i+1]);
        }
        answer = dp[1];
        //偷第一件房子
        dp[n-1] = 0;
        dp[n-2] =nums[n-2];
        for(int i = n-3;i>=0;i--){
            dp[i]=  max(nums[i]+dp[i+2],dp[i+1]);
        }
        //取得两者情况的最大值
        answer = max(answer,dp[0]);
        return answer;
        
    }
};
 