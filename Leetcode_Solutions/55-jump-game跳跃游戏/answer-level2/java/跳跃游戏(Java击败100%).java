思路：每次获得当前可以向后跳跃的最远距离jump，每走一步jump-1，并且更新jump。
更新时：如果当前nums[i]大于jump，更新为jump。
如果jump==0且当前nums[i]==0，说明无法向后跳跃并且无法更新jump，返回false。
遍历至倒数第二位（长度为1直接返回了true），jump与num[i]存在不为0的值，说明可以走到最后一位，此时循环结束，返回true。
```
class Solution {
    public boolean canJump(int[] nums) {
        int jump = 1;
        for (int i=0;i<nums.length-1;i++){
            jump = jump-1;
            if (jump==0 && nums[i]==0)
                return false;
            else if (jump<nums[i])
                jump = nums[i];
        }
        return true;
    }
}
```
