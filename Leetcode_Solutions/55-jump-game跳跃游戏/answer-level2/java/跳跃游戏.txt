自顶向下：可以减少非必要的判断
```
    private int[] dp;
    public boolean canJump(int[] nums) {
        dp = new int[nums.length];
        return solve(nums.length-1, nums);
    }
    
    private boolean solve(int index, int[] arr){
        if(index == 0)
            return true;
        
        if(dp[index] == -1)
            return false;
        
        for(int i=index-1; i>=0; i--){
            if(arr[i] + i >= index)
                return solve(i, arr);
        }
        
        dp[index] = -1;
        return false;
    }
```
