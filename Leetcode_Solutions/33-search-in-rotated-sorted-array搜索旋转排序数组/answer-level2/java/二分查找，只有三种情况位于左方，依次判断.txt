public int search(int[] nums, int target) {
		if (nums.length <= 0) {
			return -1;
		}
		int start = 0, end = nums.length - 1;
		return SearchCore(nums, target, start, end);
	}

	private int SearchCore(int[] nums, int target, int start, int end) {
		if(start > end) {
			return -1;
		}
		int mid = start + ((end - start) >> 1);
		if(nums[mid] == target) {
			return mid;
		}
		/*
		 * 只有三种情况目标值在中值左方，以4,5,6,7,0,1,2为例，设start位于4的位置，end位于2的位置
		 * 第一种是中值位于7的位置，目标值为5，此时可得出下列第一种判断条件
		 * 第二种是中值位于0的位置，目标值为5，此时可得出下列第二种判断条件
		 * 第三种是中值位于2的位置，目标值为1，此时可得出下列第三种判断条件
		 */
		else if((target >= nums[start] && nums[mid] > nums[start] && target < nums[mid])
				||(target >= nums[start] && nums[mid] < nums[start] && target > nums[mid])
				|| (target <= nums[start] && nums[mid] < nums[start] && target < nums[mid])) {
			return SearchCore(nums, target, start, mid - 1);
		}
		else {
			return SearchCore(nums, target, mid + 1, end);
		}
	}