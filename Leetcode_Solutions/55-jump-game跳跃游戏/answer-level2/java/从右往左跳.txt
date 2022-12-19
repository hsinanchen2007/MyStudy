题意是能够跳跃的**最大长度**，即nums[i]=4的话我能够跳0,1,2,3,4格，所以从右往左寻找，最左的一个能够跳跃到target的格子就是我们找到的最优格子，此时的target就变成了当前的i，然后继续向左找，直到能否找到0这个位置。
```
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length==0){
            return true;
        }
        int target = nums.length - 1;
        int i = target - 1;

        while(i >= 0){
            if(nums[i] + i >= target){
                target = i;
            }
            i--;
        }
        if(target == 0)
            return true;
        return false;
    }
}[]()
```
