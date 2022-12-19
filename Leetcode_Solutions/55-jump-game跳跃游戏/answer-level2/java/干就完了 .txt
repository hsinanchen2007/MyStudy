![屏幕快照 2019-11-16 14.44.58.png](https://pic.leetcode-cn.com/d0dc34b281a72cfb9516f9cc118d875daf4baef34ef22838e12e0eb53b15dd11-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-16%2014.44.58.png)

改编自45题跳跃游戏II

```
class Solution {
    public boolean canJump(int[] nums) {
        int end = 0;
        int maxPosition = 0;
        for(int i = 0; i < nums.length - 1; i++){
            // 找能跳的最远的
            maxPosition = Math.max(maxPosition, nums[i] + i);
            // 遇到边界，就更新边界
            if( i == end){
                end = maxPosition;
            }
        }
        return nums.length == 1 || end >= nums.length - 1 || nums[end] != 0 ;
    }
}
```
