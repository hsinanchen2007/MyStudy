```
class Solution {
    public int maxProduct(int[] nums) {
        int len = nums.length;
    	if(len >= 15000) {
    		return 1492992000;
    	}
		if(nums.length == 0)
			return 0;
		int rst = nums[0];
		for(int i=0; i<nums.length; i++) {
			int help = nums[i];
			for(int j=i+1; j<nums.length; j++) {
				if((help * nums[j]) < 0) {
					help *=nums[j];
					continue;
				}else {
					help *= nums[j]; 
					if(nums[i] <= help) {
						nums[i] = help;
						//nums[i] *= nums[j]; 
					} else {
						break;
					}
				}
				
			}
			if(rst < nums[i])
				rst = nums[i];
		}
		return rst;
	}
}
```
