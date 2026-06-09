三维数组
```
public boolean isInterleave(String s1, String s2, String s3) {
	if(s1.length() + s2.length() != s3.length()) {
		return false;
	}
	boolean[][][] dp = new boolean[s1.length() + 1][s2.length() + 1][s3.length() + 1];
	dp[0][0][0] = true;            // s1前0个与s2前0个肯定能表示s3前0个，这是平凡的
	for(int i = 1;i <= s3.length();i++) {
		for(int j = 0;j <= s1.length();j++) {
			for(int k = 0;k <= s2.length();k++) {
				if(j + k == i) {   // s1的len + s2的len = s3的len
					if(j > 0 && s3.charAt(i - 1) == s1.charAt(j - 1)) {
						dp[j][k][i] = dp[j - 1][k][i - 1];
					}
					if(k > 0 && s3.charAt(i - 1) == s2.charAt(k - 1)) {
						dp[j][k][i] |= dp[j][k - 1][i - 1];
					}
				}
			}
		}
	}
	return dp[s1.length()][s2.length()][s3.length()];
}
```

二维数组
```
public boolean isInterleave(String s1, String s2, String s3) {
	if(s1.length() + s2.length() != s3.length()) {
		return false;
	}
	boolean[][] dp = new boolean[s1.length() + 1][s2.length() + 1];
	for(int i = 0;i <= s1.length();i++) {
		for(int j = 0;j <= s2.length();j++) {
			if(i == 0 && j == 0) {
				dp[i][j] = true;   // 平凡的
			}else if(i == 0) {
				dp[i][j] = dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
			}else if(j == 0) {
				dp[i][j] = dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i - 1);
			}else {
				dp[i][j] = dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1) ||
							dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1);
			}
		}
	}
	return dp[s1.length()][s2.length()];
}
```

一维数组
```
public boolean isInterleave(String s1, String s2, String s3) {
	if(s1.length() + s2.length() != s3.length()) {
		return false;
	}
	boolean[] dp = new boolean[s2.length() + 1];
	for(int i = 0;i <= s1.length();i++) {
		for(int j = 0;j <= s2.length();j++) {
			if(i == 0 && j == 0) {
				dp[j] = true;
			}else if(j == 0) {
				dp[j] = dp[j] && s1.charAt(i - 1) == s3.charAt(i - 1);
			}else if(i == 0) {
				dp[j] = dp[j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
			}else {
				dp[j] = dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1) ||
						dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1);
			}
		}
	}
	return dp[s2.length()];
}
```