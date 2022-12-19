```
代码块
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length <= 1) return true;
        int len = nums.length;
        int tmp = 1;
        for (int i = len - 2; i > 0; i --){
            if (nums[i] >= tmp){
                tmp = 1;
            }else{
                tmp ++;
            }
        }
        if (nums[0] >= tmp){
            return true;
        }else{
            return false;
        }
    }
}
```
