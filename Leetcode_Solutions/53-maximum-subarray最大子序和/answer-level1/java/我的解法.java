```
public int maxSubArray(int[] nums) {
        int maxSum=nums[0];
        int total= nums[0];
        for(int i=1;i<nums.length;i++){
            System.out.println("maxSum"+maxSum);
            maxSum=Math.max(maxSum+nums[i],nums[i]);
            total=Math.max(total,maxSum);
        }
        return total;
    }
```
