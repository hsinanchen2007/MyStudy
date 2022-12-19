### 解题思路
此处撰写解题思路

### 代码
![java成绩.png](https://pic.leetcode-cn.com/b233d751ecb6cb61de54a5df89ce6e5b53bb2662cccac89c99da6f8db0a3fcbb-java%E6%88%90%E7%BB%A9.png)

```java
class Solution {
    public void nextPermutation(int[] nums) {
		if(nums.length==0||nums.length==1)
			return;
			for(int left=nums.length-1;left>0;left--) {
				if(nums[left]>nums[left-1]) {
					swap_new(nums,left-1);
                    next_sort(nums,left);
					return;
				}else {
					continue;
				}
			}
			Arrays.sort(nums);
			return;
		}
    private void next_sort(int[] nums, int left) {
        Arrays.sort(nums, left, nums.length);
	}
	public void swap_new(int[] nums,int pos) {
		for(int i=nums.length-1;i>pos;i--) {
			if(nums[pos]>=nums[i]) continue;
			else {
				nums[i]=nums[i]^nums[pos];
				nums[pos]=nums[i]^nums[pos];
				nums[i]=nums[i]^nums[pos];
                return;
			}
		}
	}
}
```