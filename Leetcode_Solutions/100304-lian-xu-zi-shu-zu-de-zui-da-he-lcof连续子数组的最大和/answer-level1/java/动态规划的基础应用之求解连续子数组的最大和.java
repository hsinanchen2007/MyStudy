### 解题思路
最大子数组的和一定是由当前元素和之前最大连续子数组的和叠加在一起形成的，遍历，如果之前连续子数组和大于0，则加上当前元素的值，得到更大的连续子数组和，否则直接开始一个新的连续子数组，以nums[i]开头，//每次循环都要比较这个连续子数组和是否大于之前的所有最大连续子数组的最大和，如果是则替换掉这个最大值

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int partArray = nums[0];//用于记录最大连续子数组的和
		int max = nums[0];//用于记录所有最大连续子数组的最大和
		for(int i = 1; i< nums.length;i++) {
			if(partArray > 0) {
				partArray = partArray + nums[i];
			}else {
				partArray = nums[i];
			}
			if(partArray >max)
				max = partArray;
		}
		return max;
    }
}
```