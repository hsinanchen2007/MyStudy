### 解题思路
数学题，首先题目给得有点问题，是-K和+K必须选一个；
先对数组进行排序，
那么，进行上面两种操作之后，最大值 max(A[n - 1] - K， A[i] + K)中产生；
最小值  min (A[0] + K, A[i - 1] + K)

编码的时候注意，按照中间值进行遍历。就是比如它作为中间值，就是从它之后减，在它之前加！

### 代码

```cpp
class Solution {
public:
	int smallestRangeII(vector<int>& A, int K) {
		// 数组排序
		sort(A.begin(), A.end());
		
		// 可能的最坏结果：(最大值与最小值同时加上K，或者同时减去K)
		int result = A[A.size() - 1] - A[0];
		for (int i = 1; i < A.size(); i++) {
			// 以当前i为中间点时，可能的最小值
			int minValue = min(A[0] + K, A[i] - K);
			// 以当前i为中间点时，可能的最大值
			int maxValue = max(A[A.size() - 1] - K, A[i - 1] + K);
			// 中间点的最大值与最小值的最小差值
			result = min(maxValue - minValue, result);
		}
		return result;
	}
};
```