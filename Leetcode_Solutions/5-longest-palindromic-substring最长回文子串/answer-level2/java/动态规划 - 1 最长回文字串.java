### 解题思路
第一道动态规划题目，参考勒很长时间，小白终于入门勒

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
		if(len < 2)
			return s;
		
		boolean[][] dp = new boolean[len][len];
		
		//初始化 单个字符一定是回文
		for (int i = 0; i < len; i++) {
			dp[i][i] = true;
		}
		
		int maxLen = 1;
		int index = 0;
		for (int j = 1; j < len; j++) {
			for (int i = 0; i < j; i++) {
				if(s.charAt(i) == s.charAt(j)){
					if(j - i < 3){
						dp[i][j] = true;
					}else{
						dp[i][j] = dp[i+1][j-1];
					}
				}else{
					dp[i][j] = false;
				}
				
				//记录回文的长度和起始位置
				if(dp[i][j]){
					int length = j - i + 1;
					if(length > maxLen){
						maxLen = length;
						index = i;
					}
				}
			}
			
		}
		
		return s.substring(index, index + maxLen);
    }
}
```
![image.png](https://pic.leetcode-cn.com/e6bf476be3ab72d295e47457204c634e836658667f3265c61a7a68e76924be74-image.png)
