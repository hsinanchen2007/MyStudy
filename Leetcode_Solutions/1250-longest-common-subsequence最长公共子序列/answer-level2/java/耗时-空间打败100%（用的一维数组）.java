- 执行用时 : 6 ms, 在所有 java 提交中击败了100.00%的用户
- 内存消耗 : 33.9 MB, 在所有 java 提交中击败了100.00%的用户
- 时间复杂度：O(n*m)
```java
public int longestCommonSubsequence(String text1, String text2) {
	if (text1 == null || text2 == null) return 0;
	int len1 = text1.length(), len2 = text2.length();
	if (len1 == 0 || len2 == 0) return 0;
	char[] colText, rowText;
	if (len1 > len2) {
		colText = text2.toCharArray();
		rowText = text1.toCharArray();
	} else {
		colText = text1.toCharArray();
		rowText = text2.toCharArray();
	}
	int[] dp = new int[colText.length + 1];
	for (int i = 1; i <= rowText.length; i++) {
		int tmp = 0;
		for (int j = 1; j <= colText.length; j++) {
			int prev = tmp;
			tmp = dp[j];
			if (rowText[i - 1] == colText[j - 1]) {
				dp[j] = prev + 1;
			} else {
				dp[j] = Math.max(dp[j], dp[j - 1]);
			}
		}
	}
	return dp[colText.length];
}
```
