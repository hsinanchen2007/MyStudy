### 解题思路
思路：
1. 题目给出了递推式，很容易想到用自顶向下的递归写法，把递归式改为：Tn = Tn-3 + Tn-2 + Tn-1
2. 但是一提交发现超时，原因是这个递推式用到了前三项的和，而每次求前三项的时候都是从头开始递归求，显然做了很多重复操作。
3. 所以用到了dp数组存取之前求过的结果，当下次要的时候直接取。


[个人博客地址](http://47.101.136.180/)

### 代码

```java
class Solution {
	int[] dp = new int[38];

	public int tribonacci(int n) {
		// 先判断数组中是否有结果，有直接取
		if (dp[n] != 0) {
			return dp[n];
		}

		if (n == 0) {
			return 0;
		} else if (n == 1 || n == 2) {
			return 1;
		} else {
			// 递归获取结果
			int res = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
			// 将结果保存到数组中
			dp[n] = res;
			return res;
		}
	}
}
```