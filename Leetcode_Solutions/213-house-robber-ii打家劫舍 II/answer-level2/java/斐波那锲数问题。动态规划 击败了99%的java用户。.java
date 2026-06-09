典型的斐波那锲数问题。
[更多此类问题请参考此处](https://blog.csdn.net/reed1991/article/details/53967107)
代码
```
public int rob(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        int len = nums.length;
        if(len ==  1){
            return nums[0];
        }
        if(len ==  2){
            return nums[0]>nums[1]?nums[0]:nums[1];
        }
        return Math.max(help(nums,0,len-2),help(nums,1,len-1));
        
    }
    private int help(int[] nums,int start,int end){
        int[] dp = new int[end-start+1];
        dp[0] = nums[start];
        dp[1] = Math.max(nums[start+1],nums[start]);
        
        for(int i = start+2;i<=end;i++ ){
            dp[i-start] = Math.max(dp[i-start-1],dp[i-start-2]+nums[i]);
        }
        return dp[end-start];
        
    }
```
## [更多leetcode分类题解](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)