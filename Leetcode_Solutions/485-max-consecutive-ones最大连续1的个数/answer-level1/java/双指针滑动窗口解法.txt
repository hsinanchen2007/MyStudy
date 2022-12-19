```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int left = 0;
        int right = 0;
        while(right < nums.length){
            if(nums[right]==1){
                max = Math.max(right-left+1, max);
                right++;
            }else{
                right++;
                left = right;
            }
        }
        return max;
    }
}
```
