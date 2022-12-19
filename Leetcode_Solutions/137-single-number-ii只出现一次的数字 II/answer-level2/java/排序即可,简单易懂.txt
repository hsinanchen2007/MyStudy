### 解题思路
位运算需要结合数字逻辑的知识,排序简单粗暴!

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
    	Arrays.sort(nums);
    	for(int i=0 ; i<nums.length-1 ; i++) {
    		if(nums[i]==nums[i+1]) {
    			i+=2;
    		}else {
				return nums[i];
			}
    		
    	}
    	return nums[nums.length-1];
    }
}
```