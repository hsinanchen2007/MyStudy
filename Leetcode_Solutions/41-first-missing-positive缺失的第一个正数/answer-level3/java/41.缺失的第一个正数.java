排序，相邻两数做差（后减前），如果差值大于1，前面的数+1作为返回值。当然要考虑负数等情况。

public int firstMissingPositive(int[] nums) {
		if(nums == null || nums.length == 0) return 1;
		Arrays.sort(nums);
		int i=0;
		while(nums[i]<0 && i<nums.length-1) {
			i++;
		}
		if(nums[i]<0) return 1;
		if(nums[i]>1) return 1;
		for(;i<nums.length-1;i++) {
			int x=nums[i+1]-nums[i];
			if(x>1) {
				return nums[i]+1;
			}
		}
		return nums[nums.length-1]+1;
	}