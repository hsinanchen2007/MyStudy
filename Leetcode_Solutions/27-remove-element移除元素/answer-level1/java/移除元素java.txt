```
class Solution {
    public int removeElement(int[] nums, int val) {
        int target = 0;
        for(int i=0;i<nums.length;i++){
            //若不等 则直接赋值，target指针自加
            if(nums[i] != val){
                nums[target] = nums[i];
                target++;
            }
        }
        return target;
    }
}
```
