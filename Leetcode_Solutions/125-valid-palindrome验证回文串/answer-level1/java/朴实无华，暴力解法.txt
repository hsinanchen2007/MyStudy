### 解题思路
取出字符数字并使之全部toLowerCase,循环判断，游戏结束 ，外比巴卜。

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        if (s == "" ) return true;
		StringBuilder sb = new StringBuilder();
		for(int i = 0 ; i < s.length() ;i++) {
			if(Character.isLetter(s.charAt(i))||Character.isDigit(s.charAt(i))){
				sb.append(s.charAt(i));
			}
		}
		String s1 = sb.toString().toLowerCase();
		for(int i = 0 ; i  < s1.length()/2 ; i ++) {
			if(s1.charAt(i) == s1.charAt(s1.length() -1 - i ) ) {
				continue;
			}else {
				return false;
			}
		}
		return true;
    }
}
```