### 解题思路
第一种dp[i]代表到第i个客人为止的最大服务时长：第i个客人只有两种情况，接或者不接，因为接了就代表不能接前一个客人，对应的是dp[i-2]+nums[i]，不接就直接等于dp[i-1] 
第二种dp[i]代表以第i个客人结束的最大服务时长 dp[i]=i-1个客人之前的最大时长+第i个客人时长
第二种在return前还需要对dp数组进行求最大值
### 代码

```java
//第一种
class Solution {
    public int massage(int[] nums) {
        if(nums.length==0) return 0;
        if(nums.length==1) return nums[0];
        int []dp=new int [nums.length];
        dp[0]=nums[0];
        dp[1]=intMax(nums[0],nums[1]);
        for(int i=2;i<nums.length;i++){
            dp[i]=intMax(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[dp.length-1];
    }
    public int intMax(int a,int b){
        return a>b?a:b;
    }
}
//第二种
class Solution {
    public int massage(int[] nums) {
        //建立搭配数组dp[i]代表以第i个客人结束的最大服务时长
        if(nums.length==0) return 0;
        if(nums.length==1) return nums[0];
        int []dp=new int [nums.length];
        dp[0]=nums[0];
        dp[1]=nums[1];
        //max代表第i-1个之前的最大值
        int max=dp[0];
        for(int i=2;i<nums.length;i++){
            dp[i]=max+nums[i];
            max=dp[i-1]>max? dp[i-1]:max;
        }
        max=dp[0];
        for(int i=0;i<dp.length;i++){
            if(dp[i]>max) max=dp[i];
        }
        return max;
    }
}

```