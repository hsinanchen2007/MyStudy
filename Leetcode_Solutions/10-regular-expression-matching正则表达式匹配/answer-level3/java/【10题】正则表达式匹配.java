**方法一：回溯**
```
class Solution {
    /**
    * 思路：
    * 利用回溯思想，进行逐步尝试匹配。
    */
    public boolean isMatch(String text, String pattern) {
		// 如果模式串为空，则只能匹配空的匹配串。
        if (pattern.isEmpty()){
			return text.isEmpty();
		}
		// 记录匹配串的第一个字符是否被模式串匹配。
        boolean first_match = (!text.isEmpty() &&
                               (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));
		// 模式串包含两个字符及以上并且第二个字符为* 。
        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
			// 如果模式串第三个字符往后可以匹配原匹配串
			// 或者匹配串删除第一个匹配的字符后可以被模式串匹配，则表示可匹配。
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
			// 如果模式串只有一个字符或者第二个字符不是* ，
			// 则匹配串第一个字符被模式串匹配并且分别删除第一个字符后模式串还能匹配匹配串。
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }
}
```

**方法二：动态规划-从前往后**
```
// 定义枚举对象，记录true、false和null的情况。
enum Result {
    TRUE, FALSE
}

class Solution {
    Result[][] memo;

    public boolean isMatch(String text, String pattern) {
        memo = new Result[text.length() + 1][pattern.length() + 1];
        return dp(0, 0, text, pattern);
    }

    public boolean dp(int i, int j, String text, String pattern) {
        if (memo[i][j] != null) {
            return memo[i][j] == Result.TRUE;
        }
        boolean ans;
		// 当模式串结束时，如果匹配串被匹配完则完成匹配。
        if (j == pattern.length()){
            ans = i == text.length();
        } else{
            // 按照回溯思想逐步尝试匹配。
            boolean first_match = (i < text.length() &&
                                   (pattern.charAt(j) == text.charAt(i) ||
                                    pattern.charAt(j) == '.'));

            if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                ans = (dp(i, j+2, text, pattern) ||
                       first_match && dp(i+1, j, text, pattern));
            } else {
                ans = first_match && dp(i+1, j+1, text, pattern);
            }
        }
		// 记录每个位置的匹配情况。
        memo[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }
}
```

**方法三：动态规划-从后往前**
```
class Solution {
    public boolean isMatch(String text, String pattern) {
        boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
        dp[text.length()][pattern.length()] = true;

        for (int i = text.length(); i >= 0; i--){
            for (int j = pattern.length() - 1; j >= 0; j--){
                boolean first_match = (i < text.length() &&
                                       (pattern.charAt(j) == text.charAt(i) ||
                                        pattern.charAt(j) == '.'));
                if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
}
```
