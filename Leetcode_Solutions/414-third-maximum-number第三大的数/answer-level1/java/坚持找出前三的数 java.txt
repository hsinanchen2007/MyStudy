```
class Solution {
    public static int thirdMax(int[] nums) {
		int max = Integer.MIN_VALUE;
		int second = Integer.MIN_VALUE;
		int three = Integer.MIN_VALUE;
        HashSet<Integer> set = new   HashSet<Integer>();
		for (int i = 0; i < nums.length; i++) {
            // 计算重复的个数
            set.add(nums[i]);
			if (nums[i] > max) {
                three = second;
				second = max;
				max = nums[i];
			} else if (nums[i] > second && nums[i] < max) {
				three = second;
				second = nums[i];
			} else if ((nums[i] > three && nums[i] < second)) {
				three = nums[i];
			}
		}
		if (three == Integer.MIN_VALUE && set.size() < 3) {
			return max;
		} else {
			return three;
		}
	}
	
}
```
