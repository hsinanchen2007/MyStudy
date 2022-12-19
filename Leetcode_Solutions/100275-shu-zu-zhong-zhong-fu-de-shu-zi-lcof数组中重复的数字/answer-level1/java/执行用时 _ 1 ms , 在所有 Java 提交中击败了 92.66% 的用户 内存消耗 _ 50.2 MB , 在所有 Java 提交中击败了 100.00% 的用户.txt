```
public static int findRepeatNumber(int[] nums) {
	int length = nums.length;
	for (int i = 0; i < length; i++) {
		int value = nums[i];
		int toValue = nums[value];
		if (value == i)
			continue;
		if (value == toValue) {
			return value;
		}
		int temp;
		temp = nums[value];
		nums[value] = nums[i];
		nums[i] = temp;
	}

	return -1;
}
```