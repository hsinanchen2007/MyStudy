```
    public int singleNumber(int[] nums) {
        if(nums.length == 1) {
			return nums[0];
		}
		Arrays.sort(nums);
		int i = 0;
		while(i < nums.length) {
            //每次取两个数进行比较，若不同，返回第一个数
			if(nums[i] != nums[i + 1]) {
				return nums[i];
			}
			i += 2;
			if(i == nums.length - 1) {
				return nums[nums.length - 1];
			}
		}
		return -1;
    }
```
