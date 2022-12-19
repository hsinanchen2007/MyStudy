	public int pivotIndex(int[] nums) {
		//先求和，再每次减去当前值得到的值乘以2（因为两边相等所以乘2即相当于两边求和）再加上当前值应该等于总和
		int sum = 0;
		for (int i = 0; i < nums.length; i++) {
			sum += nums[i];
		}
		int rightSum = sum;
		for (int i = 0; i < nums.length; i++) {
			rightSum -= nums[i];//先减去当前值
			if(rightSum*2+nums[i]  == sum) { //如果等于返回i
				return i;
			}
		}
		return -1;
	}