# 思路
1. 整数对60取模，可能有60种余数。故初始化一个长度为60的数组，统计各余数出现的次数。
2. 遍历time数组，每个值对60取模，并统计每个余数值（0-59）出现的个数。因为余数部分需要找到合适的cp组合起来能被60整除。
3. 余数为0的情况，只能同余数为0的情况组合（如60s、120s等等）。0的情况出现k次，则只能在k中任选两次进行两两组合。本题解单独写了个求组合数的方法，也可以用k * (k - 1) / 2表示。
4. 余数为30的情况同上。
5. 其余1与59组合，2与58组合，故使用双指针分别从1和59两头向中间遍历。1的情况出现m次，59的情况出现n次，则总共有m*n种组合。 

# 题解
```
	public int numPairsDivisibleBy60(int[] time) {
		int count = 0;
		int[] seconds = new int[60];
		for(int t : time) {
			seconds[t % 60] += 1; 
		}
		count += combination(seconds[30], 2);
		count += combination(seconds[0], 2);
		int i = 1, j = 59;
		while(i < j) {
			count += seconds[i++] * seconds[j--];
		}
		return count;
	}
	
	// 求组合数
	public int combination(int n, int k) {
		long result = 1;
		for(int i = 1; i <= k; i++) {
			result = result * (n - i + 1) / i;
		}
		return (int)result;
	}
```

# 时间和空间复杂度
**时间复杂度**：O(n)
**空间复杂度**：O(1) 固定空间开销（长度为60的数组）