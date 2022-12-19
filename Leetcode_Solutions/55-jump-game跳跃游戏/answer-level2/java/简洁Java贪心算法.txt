
使用贪心算法。核心思想：
1. 设置可跳的步数为 toJump
2. 如果在当前位置，可跳为0，则肯定无法到最后
3. 每个格子更新可跳的位置

```Java
class Solution {
    public boolean canJump(int[] nums) {
        // 求出每个位置，能够去到最远的地方，如果只能在原地了，则不能更远了
        int toJump = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (toJump == 0) return false;
            toJump = Math.max(toJump - 1, nums[i]);
        }
        return true;
    }
}
```