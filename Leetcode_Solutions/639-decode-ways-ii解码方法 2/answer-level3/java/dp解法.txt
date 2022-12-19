### 解题思路
要考虑的情况会多一点

### 代码

```java
class Solution {
   public int numDecodings(String s) {

if(s.charAt(0)=='0'){
return 0;
}
		long[] dp = new long[s.length() + 1];
		int mod = 1000000007;
		dp[1] = s.charAt(0) == '*' ? 9 : 1;
		dp[0] = 1;
		for (int i = 2; i <= s.length(); i++) {
			char c = s.charAt(i - 1);
			if (c == '*') {
				dp[i] = dp[i - 1] * 9;//single decode
				if (s.charAt(i - 2) == '1') {
					dp[i] = (dp[i] + dp[i - 2] * 9) % mod;
				} else if (s.charAt(i - 2) == '2') {
					dp[i] = (dp[i] + dp[i - 2] * 6) % mod;
				} else if (s.charAt(i - 2) == '*') {
					dp[i] = (dp[i] + 15 * dp[i - 2]) % mod;

				}
			} else {
				if (c == '0') {
					if (s.charAt(i - 2) == '1' || s.charAt(i - 2) == '2' || s.charAt(i - 2) == '*') {
						dp[i] = dp[i - 2] + (s.charAt(i - 2) == '*' ? dp[i - 2] : 0);
						continue;
					}

					return 0;
				}
				dp[i] = dp[i - 1];//single decode
				if (s.charAt(i - 2) == '1' || s.charAt(i - 2) == '2' && c <= '6') {
					dp[i] = (dp[i] + dp[i - 2]) % mod;
				} else if (s.charAt(i - 2) == '*') {
					if (c <= '6') {
						dp[i] = (dp[i] + dp[i - 2] * 2) % mod;
					} else {
						dp[i] = (dp[i] + dp[i - 2]) % mod;
					}
				}
			}

		}
		return (int) (dp[s.length()] % mod);
	}
}
```