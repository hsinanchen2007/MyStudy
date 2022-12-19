从最后一位开始寻找这位后面比它还小的数字,交换这两个数字,然后把剩下的元素排序.
```
class Solution {
    public void nextPermutation(int[] nums) {
		for(int i = nums.length-1; i>=0; i--) {
			for(int j = nums.length-1; j>i; j--) {
				if(nums[i]<nums[j]) {
					int t = nums[i];
					nums[i] = nums[j];
					nums[j] = t;
					int[] trans = new int[nums.length-i-1];
					System.arraycopy(nums, i+1, trans, 0, trans.length);
					Arrays.sort(trans);
					System.arraycopy(trans, 0, nums, i+1, trans.length);
					return;
				}
			}
		}
		Arrays.sort(nums);
	}
}
```
