### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int jump(int[] nums) {
		return jump(nums,0);
    }
	public int jump(int[] nums, int index) {
		if(index == nums.length-1) return 0;
		if(nums[index]>=nums.length-1-index) return 1;
		int maxindex = index+1;
		for(int i = index+2;i<nums.length&&i<index+nums[index]+1;i++) {
			if(i+nums[i]>maxindex+nums[maxindex]) maxindex = i;
		}
		return jump(nums,maxindex)+1;
	}
}
```