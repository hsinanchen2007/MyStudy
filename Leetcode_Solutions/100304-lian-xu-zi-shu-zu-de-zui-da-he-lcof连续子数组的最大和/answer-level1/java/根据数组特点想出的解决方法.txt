### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums==null || nums.length==0) {
			return 0;
		}
		int curSum=0,maxSum=nums[0];
		for(int i=0;i<nums.length;i++) {
			if(curSum<=0) {
				curSum=nums[i];
			}else {
				curSum+=nums[i];
			}
			if(curSum>maxSum) {
				maxSum=curSum;
			}
		}
		return maxSum;
    }
}
```