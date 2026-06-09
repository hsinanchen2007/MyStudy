### 解题思路


### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
            if(p.length() == 0)
			return s.length()==0;
		
		boolean firstMatch = s.length() > 0 && (s.charAt(0)==p.charAt(0) || p.charAt(0)=='.');
		
		if(p.length() >= 2 && p.charAt(1) == '*'){
			return isMatch(s, p.substring(2)) || (firstMatch&&isMatch(s.substring(1), p));
		}else{
			return firstMatch && isMatch(s.substring(1), p.substring(1));
		}
    }
}
`
``![image.png](https://pic.leetcode-cn.com/9a7f3ffb968f7f1e7b88601ee5945673d67735d2e05ac03eae3670b7fbde30a4-image.png)
