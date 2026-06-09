### 解题思路
此处撰写解题思路
helper是我想得暴力解决的方法
nums[index] + helper(nums,index+2)代表的是抢劫当前的房屋所累积的和
helper(nums,index+1)代表不抢劫当前房屋

dp时根据我helper来改写的
至于为什么要写dp[dp.length-2] = nums[nums.length-1]，是为了不越界，而且自己画画图可以得到的。

有什么不对的地方请及时联系我，我方便修改，我也是小白一枚

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        //return helper(nums,0);
        return dp(nums);
    }

    public int helper(int[] nums,int index){
        if(index >= nums.length){
            return 0;
        }
        return Math.max(nums[index]+helper(nums,index+2),helper(nums,index+1));
    }

    public int dp(int[] nums){
        if(nums == null) {return 0;}
        if(nums.length<1){return 0;}
        if(nums.length <2){return nums[0];}
        if(nums.length == 2){return Math.max(nums[0],nums[1]);}
        int[] dp = new int[nums.length+1];
        dp[dp.length-1] = 0;
        dp[dp.length-2] = nums[nums.length-1];
        for(int i=dp.length-3; i>=0; i--){
            dp[i] = Math.max(nums[i] + dp[i+2],dp[i+1]);
        }

        return dp[0]>dp[1]?dp[0]:dp[1];
    }
}
```