

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
		int[][] re = new int[n][n];
		int num = 1;
		int up = 0, down = n - 1, right = n - 1, left = 0;
		while (num <= n * n) {
			if (num==n*n) {
				re[up][right]=num;
				num++;

			}

			for (int i = left; i < right; i++) {
				re[up][i] = num;//
				// 上
				num++;
			}

			for (int i = up; i < down; i++) {
				// 右
				re[i][right] = num;
				num++;
			}
			for (int i = right; i > left; i--) {
				// 下
				re[down][i] = num;
				num++;
			}
			for (int i = down; i > up; i--) {
				// 左
				re[i][left] = num;
				num++;
			}
			up++;
			down--;
			left++;
			right--;

		}

		return re;
    }
}
```