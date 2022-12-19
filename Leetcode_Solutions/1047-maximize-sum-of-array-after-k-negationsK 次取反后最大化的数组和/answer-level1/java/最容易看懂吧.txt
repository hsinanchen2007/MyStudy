### 解题思路
1.排序
2.遍历，负数弄正，同时求和sum
3.剩下的K为偶，则返回sum；为奇，找最小值，返回sum-2*min

### 代码

```java
class Solution {
   public int largestSumAfterKNegations(int[] A, int K) {
		Arrays.sort(A);
		// 先将所有负数弄正。
		int sum = 0;
		for (int i = 0; i < A.length; i++) {
			if (A[i] <= 0 && K > 0) {
				A[i] = -A[i];
				K--;
			}
			sum += A[i];
		}
		//看剩下的K是奇是偶。
		if (K > 0) {
			if (K % 2 == 0) {
				return sum;
			} else {
				//奇数
				 Arrays.sort(A);
				return sum - 2 * A[0];
			}
		}
		return sum;
	}
}
```