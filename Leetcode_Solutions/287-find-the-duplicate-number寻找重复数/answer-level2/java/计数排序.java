```
    public int findDuplicate(int[] nums) {
        if(nums == null || nums.length <2){
            return Integer.MIN_VALUE;
        } 
        int max = Integer.MIN_VALUE;
		for (int i = 0; i < nums.length; i++) {
			max = Math.max(max, nums[i]);
		}
		int[] bucket = new int[max + 1];
		//统计每个数字的个数存入bucket中
		for (int i = 0; i < nums.length; i++) {
			bucket[nums[i]]++;
            if(bucket[nums[i]]>1){
                return nums[i];
            }
		}
        return Integer.MIN_VALUE;
    }
```
