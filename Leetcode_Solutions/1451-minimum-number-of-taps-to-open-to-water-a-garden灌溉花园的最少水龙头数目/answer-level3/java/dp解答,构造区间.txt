### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minTaps(int n, int[] ranges) {
		int[][] data = new int[n + 1][2];
		for (int i = 0; i < ranges.length; i++) {
			data[i][0] = i - ranges[i];
			data[i][1] = i + ranges[i]-1;

		}
		Arrays.sort(data, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[1] - o2[1];
			}
		});
		int[] dp = new int[n];
		Arrays.fill(dp, Integer.MAX_VALUE / 2);
		for (int[] temp : data) {

			if (temp[0] <= 0) {
				for (int j = 0; j <= Math.min(n-1, temp[1]); j++) {
					dp[j] = 1;
				}
			} else {
				for (int j = temp[0]; j <=Math.min(n-1, temp[1]); j++) {
					dp[j] = Math.min(dp[j], dp[temp[0]-1] + 1);
				}
			}
		}
		return dp[n-1] >= Integer.MAX_VALUE / 2 ? -1 : dp[n-1];
	}
}
```