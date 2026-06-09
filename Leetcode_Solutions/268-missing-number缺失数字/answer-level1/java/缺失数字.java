解法：这个题可以这么来理解，求0...n的序列的集合中缺失的某个数字，
按照计算运算的方法，求0...n的序列的和，减去数组中所有的元素，得到
的解答就是缺失的数字。用一个for循环从1...n，循环里的第一步是求和，第二步
是取出数组中i-1的元素自减，最后的结果就是缺失的元素。

```
public int missingNumber(int[] nums) {
	int n = nums.length();
	int sum = 0;
	for(int i = 1;i<=n;i++){
		sum+=i；
		sum-=nums[i-1];
	}
	return sum;
}
```

