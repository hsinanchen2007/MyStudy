### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	public void merge(int[] A, int m, int[] B, int n) {
		int[] C = new int[m];
		int i = 0, j = 0, k = 0;
		for (i = 0; i < m; i++) {
			C[i] = A[i];
		}
		i = 0;
		for (k = 0; k < m + n; k++) {

			if (i == m) {

				A[k] = B[j];
				j++;
				continue;
			}
			if (j == n) {
				A[k] = C[i];
				i++;
				continue;
			}
			if (C[i] <= B[j]) {
				A[k] = C[i];

				i++;
			} else {
				A[k] = B[j];
				j++;
			}
		}

	}
}
```