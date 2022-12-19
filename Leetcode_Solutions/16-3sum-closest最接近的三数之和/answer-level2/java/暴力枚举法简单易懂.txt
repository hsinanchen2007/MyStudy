穷举出所有可能计算与target差的绝对值算到最小的num
```
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int num = nums[0] + nums[1] + nums[2];
        for (int i = 0; i+2 < nums.length; i++) {
			for (int j = i+1; j+1 < nums.length; j++) {
				for (int z = j+1; z < nums.length; z++) {
					int a,b;
					if(num - target >= 0) {
						a = num - target;
					}else {
						a = target - num;
					}
					
					if(nums[i] + nums[j] + nums[z] - target >= 0) {
						b = nums[i] + nums[j] + nums[z] - target;
					} else {
						b = target - nums[i] - nums[j] - nums[z];
					}
					if(a>b) {
						num = nums[i] + nums[j] + nums[z];
					}
				}
			}
		}
        return num;
    }
}
```
