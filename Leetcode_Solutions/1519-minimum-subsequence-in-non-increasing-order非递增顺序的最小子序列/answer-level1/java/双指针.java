### 解题思路
定义逆序和sum，顺序和curSum，比较大小就ok了

```java
class Solution {
 	public List<Integer> minSubsequence(int[] nums) {
        	Arrays.sort(nums);
		ArrayList<Integer> arr = new ArrayList<Integer>();
		int left = 0;
		int right = nums.length - 1;
		int sum = nums[right];
		int curSum = nums[left];
		arr.add(nums[right]);
		while(left < right) {
			if(curSum < sum) {
				curSum += nums[++left];
				continue;
			}
			sum += nums[--right];
			arr.add(nums[right]);
		}
		return arr;
	}
}
```