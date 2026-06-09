### 解题思路
这道题用递归可以简化思路，实现简单

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        if (p.length() <= 0) 
			return s.length() <= 0;
	    boolean match = (s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.'));
	    if (p.length() > 1 && p.charAt(1) == '*'){
	        return isMatch(s, p.substring(2)) || (match && isMatch(s.substring(1), p));
	    } else {
	        return match && isMatch(s.substring(1), p.substring(1));
	    }
    }
}
```