![image.png](https://pic.leetcode-cn.com/451769be7eaa71035155d757d9047d7ade70441c990c89891bc1a1622ee4846d-image.png)


对于dp[i]：
    1.如果右移出去的那个值，不大于dp[i-1]，则认为最大值还在里面，dp[i] = max(dp[i], nums[i+k-1])
    2.移出去的值为dp[i-1]，则遍历新窗口，获取最大值。


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0) return nums;
        if (nums.size() - k < 0) return nums;
        vector<int> dp(nums.size() - k + 1, INT_MIN);

        //init the first dp
        for(int i=0; i<k; i++){
            dp[0] = max(dp[0], nums[i]);
        }

        for(int i=1; i< dp.size() ; i++) {
            //normal  dp 
            if(dp[i-1] > nums[i-1]){
                dp[i] = max(dp[i-1], nums[i+k-1]);
            }else{
                //one by one choose
                for(int j=i;j<i+k; j++){
                    dp[i] = max(nums[j],dp[i]);
                }
            }
        }
        return dp;
    }
};