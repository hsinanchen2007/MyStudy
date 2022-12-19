```
class Solution {
    
    public void sortColors(int[] nums) {
        
        for(int i=1;i<nums.length;i++){
            for(int j=i;j>0;j--){
                if(nums[j] < nums[j-1]) {
                    int temp = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
}
```
