## 思路
由于数组仅翻转了一次，可以看做是两段有序数组，并且第一段数组的所有值都比第二段的都大，此时有三种情况：
 - 我们将数组一分为二，如果左边界比中间大，则最小值在左边；
 - 如果中间比右边界大，则最小值在右边；
 - 如果数组有序，则左边界则为最小值。

注意：mid在左边时，需要+1；但mid在右边时，要保持不变（此时mid可能是最小值）

## 实现
```
class Solution {
	public int findMin(int[] nums) {
		int l = 0,r = nums.length-1;
		while (true) {
			int mid = l + (r - l) / 2;
			if (nums[l] > nums[mid]) {
				r = mid;
				continue;
			}
			if (nums[mid] > nums[r]) {
				l = mid + 1;
				continue;
			}
			return nums[l];
		}
	}
}
```