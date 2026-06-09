### 解题思路
此处撰写解题思路
思路理解了半天，才弄明白，不知道以后还能不能再独立完成
### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        if(s==null || s.length() <= 1)
			return 0;
		
		int n = s.length();
		int max = 0;
		//dp[i]表示以第i个字符结尾的字符串中最长有效括号字串的长度(i >= 1)
		int[] dp = new int[n];
		
		/*for(int i = 1;i < n;i ++){
			if(s.charAt(i) == ')'){ //只考虑最后一个字符为')'
				if(s.charAt(i-1) == '('){
					dp[i] = (i >= 2)?dp[i-2]+2 : 2;
				}else{ //s.charAt(i-1) == ')'
					if(i-dp[i-1]-1 >= 0 && s.charAt(i-dp[i-1]-1) == '('){ //
						dp[i] = dp[i-1] + ((i-dp[i-1]) >= 2?dp[i-dp[i-1]-2]+2 : 2);
					}
				}
			}
		}*/
		
		for(int i = 1;i < n;i ++){
			if(s.charAt(i) == ')'){
				if(s.charAt(i-1) == '('){
					dp[i] = (i-1 > 0)?dp[i-2]+2 : 2;
				}else{ //s.charAt(i-1) == ')'
					if(i-dp[i-1]-1 >= 0 && s.charAt(i-dp[i-1]-1) == '('){
						if(i-dp[i-1]-2 >= 0){
							dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2; 
						}else{
							dp[i] = dp[i-1] + 2;
						}
					}
				}
			}
			max = Math.max(max, dp[i]);
		}
		return max;
		
    }
}
```
![image.png](https://pic.leetcode-cn.com/39fcea7dc2a91d8c8cb8e99b8825df4f0c73c6520524d622dfca0c0e3fa13fb2-image.png)
