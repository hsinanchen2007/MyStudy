


```
    public int rob(int[] nums) {
        if(nums==null||nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return nums[0];
        }
        if(nums.length==2){
            return Math.max(nums[0],nums[1]);
        }
        int[] dp=new int[nums.length];
        dp[0]=nums[0];
        dp[1]=Math.max(nums[1],nums[0]);
        for(int i=2;i<nums.length;i++){
            /*可与选在上一个或者本个+往上两个*/
            dp[i]=Math.max(dp[i-1],nums[i]+dp[i-2]);
        }
        return  dp[nums.length-1];
    }
```
