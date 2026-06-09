```
class Solution {
    public boolean canJump(int[] nums) {
        int maxJump = nums[0]  ;
        // 动态规划 maxJump表明当前可以到达最远的index 
        // maxJump = Math.max(maxJump,i + nums[i])
        for (int i=1 ;i<nums.length ;i++) {
            if (i > maxJump)
                return false ;
            if (maxJump >= nums.length)
                return true ;
            maxJump = Math.max(maxJump,i + nums[i]) ;
        }
        return true ;
    }
}
```
