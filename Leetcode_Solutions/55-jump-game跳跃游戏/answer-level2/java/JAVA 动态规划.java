算法思想dp为当前能到达最远位置
如果当前dp为0则返回false
遍历整个数组更新dp,判断能否到达最后一位
```
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length==1) {
			return true;
		}else {
			int dp=nums[0];
			for(int i=1;i<nums.length;i++) {
				if(dp==0) {
					return false;
				}else if(dp-1+i>=nums.length-1) {
					return true;
				}
				else {
					dp=Math.max(dp-1, nums[i]);
					
				}
			}
			return true;
		}
    }
}
```
