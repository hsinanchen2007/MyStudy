动态规划
```
    public int maxProduct(int[] nums) {
        int len = nums.length;
        int[] maxDp = new int[len];
        int[] minDp = new int[len];
        maxDp[0] = Math.max(nums[0], 0);
        minDp[0] = Math.min(nums[0], 0);
        int ans = nums[0];
        
        for(int i=1; i<len; i++){
            int val = nums[i];
            if(val > 0) {
                maxDp[i] = Math.max(maxDp[i-1] * val, val);
                minDp[i] = minDp[i-1] * val; 
            }
            else {  
                maxDp[i] = minDp[i-1] * val; 
                minDp[i] = Math.min(maxDp[i-1] * val, val);
            }
            ans = Math.max(maxDp[i], ans);
        }
        
        return ans;
    }
```
