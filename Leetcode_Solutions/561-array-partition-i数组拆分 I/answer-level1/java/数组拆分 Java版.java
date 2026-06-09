
```Java []
class ArrayPairSum{
	/**
	 * 1.规律：先排序，从0开始，对于偶数位的元素求和，即为解
	 * 
	 * 执行用时 :37 ms, 在所有 Java 提交中击败了31.70%的用户
	 * 内存消耗 :50 MB, 在所有 Java 提交中击败了36.81%的用户
	 */
	public int arrayPairSum1(int[] nums) {
		Arrays.sort(nums);
		int minSum = 0;
		for(int i = 0 ; i < nums.length; i+=2) {
			minSum += nums[i];
		}
		return minSum;
	}
}
```
