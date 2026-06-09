```
class Solution {
    public int singleNumber(int[] nums) {
        if(nums==null|nums.length<1){
            return 0;
        }
        
        int temp = 0;
        for(int i = 0;i<nums.length;i++){
            temp = temp^nums[i];
        }
        return temp;
    }
}
```
