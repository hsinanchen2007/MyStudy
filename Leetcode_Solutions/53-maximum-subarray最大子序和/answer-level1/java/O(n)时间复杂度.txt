```
class Solution {
     public int maxSubArray(int[] nums) {
        int sum = nums[0], max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if(sum < 0){
                sum = nums[i];
            }else{
                sum += nums[i];
            }
            
            if(max < sum){
                max = sum;
            }
        }
        return max;
    }
}
```
