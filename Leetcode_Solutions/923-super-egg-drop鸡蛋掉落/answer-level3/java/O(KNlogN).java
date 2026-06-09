### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int superEggDrop(int K, int N) {

		int[][] dp = new int[N + 1][K + 1];
		for (int i = 1; i <= N; i++) {
			dp[i][1] = i;
		}
		for (int i = 1; i <= K; i++) {
			dp[1][i] = 1;
		}
		for (int i = 2; i <= N; i++) {
			for (int j = 2; j <= K; j++) {
				int start = 1, end = i, mid;

				while (true) {
					if (end - start <= 1) {
						dp[i][j] = 1+Math.min(Math.max(dp[start - 1][j - 1], dp[i - start][j]),
								Math.max(dp[end - 1][j - 1], dp[i - end][j]));
						break;
					}
					mid = (start + end) / 2;
					int temp1 = dp[mid - 1][j - 1];
					int temp2 = dp[i - mid][j];
					if (temp1 > temp2) {
						end = mid;
					} else if (temp1 < temp2) {
						start = mid;
					} else {
						dp[i][j] = temp1+1;
						break;
					}

				}
			}
		}
		return dp[N][K];

	}
}
```