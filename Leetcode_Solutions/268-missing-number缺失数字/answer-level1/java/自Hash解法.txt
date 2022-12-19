因为数的范围是0-n,因此可以用数组本身的元素来hash从而节省空间。
```
class Solution {
    public int missingNumber(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            nums[i]++;
        }
        int MAX = 1;
        for(int i = 0; i < nums.length; i++){
            if(Math.abs(nums[i]) == nums.length+1){
                MAX = -1; 
            }else{
                nums[Math.abs(nums[i])-1] = nums[Math.abs(nums[i])-1] * -1;
            }
        }

        int result = nums.length;

        for(int i = 0; i < nums.length; i++){
            if(nums[i] > 0){
                return i;
            }
        }


        return result;
    }
}
```
