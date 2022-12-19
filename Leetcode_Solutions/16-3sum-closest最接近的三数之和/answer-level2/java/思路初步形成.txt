### 解题思路
双指针法

### 代码

```java
class Solution {*斜体*
    public int threeSumClosest(int[] nums, int target) {
        if(nums==null || nums.length<3)
			return Integer.MAX_VALUE;
		
		Arrays.sort(nums);
		
		int min = nums[0] + nums[1] + nums[2];
		for(int i = 0;i < nums.length;i ++) {
			int j = i+1;
			int k = nums.length - 1;
			
			while(j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				int abs = Math.abs(sum - target);
				if(abs == 0) {
					return sum;
				}else {
					if(abs < Math.abs(min - target)) {
						min = sum;
					}else if(abs > Math.abs(min - target)) {
						
					}
					if(sum > target) {
						k --;
					}else if(sum < target) {
						j ++;
					}else {
						return min;
					}
				}
 			}
		}
		return min;
    }
}
```
![image.png](https://pic.leetcode-cn.com/24ab8ce32e644262429f45deeda26227686212f1313c79762d743194e233d493-image.png)
