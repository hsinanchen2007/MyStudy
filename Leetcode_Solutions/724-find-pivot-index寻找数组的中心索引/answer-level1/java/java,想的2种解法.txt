开始是暴力解决办法：左边加一遍，右边加一遍
```
/**
	 * 暴力解决方法
	 * 用时：350ms
	 * 内存消耗：59.9MB
	 * 已通过！！
	 * @param nums
	 * @return
	 */
	public int pivotIndex(int[] nums) {
		if(nums.length>=3){
			int left = 0;
			int right = 0;
			for(int i = 0; i < nums.length; i++){
				left = i-1;
				right = i+1;
				int l_value = 0;
				int r_value = 0;
				while(left>=0){
					l_value+=nums[left];
					left--;
				}
				while(right<nums.length){
					r_value+=nums[right];
					right++;
				}
				if(l_value==r_value){
					return i;
				}
			}
		}else{
			return -1;
		}
		return -1;
    }
```


优化方案：右边和=总和-左边和-当前值，只循环了2遍
```
/**
	 * 优化方案
	 * 执行时间：6ms
	 * 内存消耗：50.1MB
	 */
	public int pivotIndexOpt(int[] nums){
		//1.计算总和
		int sum = 0;
		for(int num:nums){
			sum+=num;
		}
		int left_num = 0;
		for(int p = 0;p<nums.length;p++){
			if(p!=0){
				left_num+=nums[p-1];
			}
			int right_num = sum-left_num-nums[p];
			if(left_num==right_num){
				return p;
			}
		}
		return -1;
	}
```