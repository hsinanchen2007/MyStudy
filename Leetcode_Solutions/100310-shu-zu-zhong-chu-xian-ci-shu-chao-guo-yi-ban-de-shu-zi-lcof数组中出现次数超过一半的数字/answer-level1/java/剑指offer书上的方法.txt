### 解题思路
因为出现最多的数超过数组一半，所以最后times一定--不到0，当时的result保存的是出现最多的数字

### 代码

```java

  class Solution {
  	public int majorityElement(int[] nums) {
		
		if(nums==null&&nums.length<1) {
			return 0;
		}
		int result = nums[0];
		int times = 1;
		
		for (int i = 1; i < nums.length; i++) {
			if(times==0) {
				result = nums[i];
                times = 1;
			}else if(result==nums[i]){
				times++;
			} else {
				times--;
			}
			
		}
		return result;
    }
}

```