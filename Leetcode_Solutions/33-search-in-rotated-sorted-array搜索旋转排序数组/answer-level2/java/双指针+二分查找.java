思路：左右两个指针找旋转点，并同时与目标元素比较，如果到旋转点，目标元素还没有找到，则再用二分查找去找目标元素。
```
public int search(int[] nums, int target) {
		int length = nums.length;
		if(length < 1) {
			return -1;
		}
		int left = 0;
		int right = length-1;
		while (nums[left] > nums[right]) {
			if(nums[left] == target) {
				return left;
			} else if(nums[right] == target) {
				return right;
			} else {
				left ++;
				right --;
			}
			
		}
		int medium = (left+right)/2;
		while(left <= right) {
			if(nums[medium] == target) {
				return medium;
			} else if(nums[medium] > target) {
				right = medium - 1;
			} else {
				left = medium + 1;
			}
			medium = (left + right)/2;
		}
		
		return -1;
	}
```
