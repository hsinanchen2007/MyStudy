```
class Solution {
    public int findMin(int[] nums) {
        int index = 0;
        for(int i = 1; i < nums.length; i++){
            if(nums[i - 1] > nums[i]){
                index = i;
            }
        }
        return nums[index];
    }
}
```
