### 解题思路
思路清晰

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        if(p.length() == 0)
			return s.length()==0;
		if(p == null)
			return s == null;
		
		int m = s.length();
		int n = p.length();
		
		//二维矩阵，索引是从0开始，长度+1
		boolean[][] dp = new boolean[m+1][n+1];
		
		//初始化
		dp[0][0] = true;
		for(int i = 2;i <= n;i ++){ //长度
			if(p.charAt(i-1) == '*'){//索引
				dp[0][i] = dp[0][i-2];
			}
		}
		
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				char cs = s.charAt(i-1);
				char cp = p.charAt(j-1);
				if(cs == cp || cp == '.') { //不包含*
					dp[i][j] = dp[i-1][j-1];
				}else if(cp == '*'){
					if(dp[i][j-2]){
						dp[i][j] = true;
					}
					else if(cs==p.charAt(j-2) || '.'==p.charAt(j-2)){ //s往后移一位，*匹配一次或者多次前面的字符
						dp[i][j] = dp[i-1][j];
					}else{//*不用来匹配前面的字符
						dp[i][j] = dp[i][j-2];
					}
				}
				
			}
		}
		
		return dp[m][n];
    }
}
```
![image.png](https://pic.leetcode-cn.com/3c77b9424abae511b5bfb1a95486310ca6760b631e7300622fe97111637d8183-image.png)
