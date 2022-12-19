```
public int threeSumClosest(int[] nums, int target) {
        int len = nums.length;
		Arrays.sort(nums);
		int res = nums[0] + nums[1] + nums[len - 1];
		for (int i = 0; i < len - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1;
			int right = len - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (target - sum > 0) {
                    while (left < right && nums[left + 1] == nums[left]) {
                        left++;
                    }
                    left++;
				} else if (target - sum < 0) {
					while (left < right && nums[right - 1] == nums[right]) {
                        right--;
                    }
                    right--;
				} else {
					return target;				
				}
				if (Math.abs(target - sum) < Math.abs(target - res)) {
					res = sum;
				}
			}
		}
		return res;
    }
```
