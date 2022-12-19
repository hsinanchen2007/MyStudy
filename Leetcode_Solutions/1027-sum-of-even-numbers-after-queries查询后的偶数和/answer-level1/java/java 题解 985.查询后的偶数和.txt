## 执行
```
执行用时 : 5 ms, 在Sum of Even Numbers After Queries的Java提交中击败了99.90% 的用户
内存消耗 : 57.7 MB, 在Sum of Even Numbers After Queries的Java提交中击败了92.42% 的用户
```
## 思路
思路和官方题解的一致，不过优化了if语句的执行时间。
之前本来是用的%2的操作来判断是否为偶数，但是遇到个问题就是数字为负数，%2操作之后为-1，进行乘法运算答案是错误的。碰巧在评论去看到有人判断偶数用的是&1操作，恍然大悟，所以就改成了&1。

## 实现

```
class Solution {
	public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
		int sum = 0;
		int[] result = new int[queries.length];
		for (int i = 0; i < A.length; i++) {
			sum += (((A[i]+1) & 1) * A[i]);
		}
		for (int i = 0; i < queries.length; i++) {
			sum -= (((A[queries[i][1]]+1)&1) * A[queries[i][1]]);
                        A[queries[i][1]] = (A[queries[i][1]] + queries[i][0]);
			sum += (((A[queries[i][1]]+1)&1) * A[queries[i][1]]);
			result[i] = sum;
		}
		return result;
	}
}
```