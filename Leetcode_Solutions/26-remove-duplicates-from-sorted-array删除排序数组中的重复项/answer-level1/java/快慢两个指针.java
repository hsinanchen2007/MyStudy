慢指针i初始化为0，快指针初始化为1.判断快慢指针所指数字是否相等，若相等，则直接跳过，直到找到不等的数字，直接将那个不等的数移到慢指针的后一个位置，慢指针加1，快指针重复这一过程，直到快指针遍历完整个数组
```
class Solution {

	public int removeDuplicates(int[] nums) {
		int len = nums.length;
		int i=0;
		for (int j=1; j<len; j++) {
            //遇到相同的则跳过，遇到不同的，则往前覆盖掉
			if (nums[j] != nums[i]) {
				i++;
				nums[i] = nums[j];
			}
		}
		return i+1;
	}
	
}
```
