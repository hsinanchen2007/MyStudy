### 解题思路

见代码

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        return isPalindrome(x + "");
    }
    /**
     * 判定字符串是否是回文串
     * @param s 待判定的字符串
     * @return true or false
     */
    public boolean isPalindrome(String s) {
        int len = s.length();
		for (int i = 0; i < len / 2; i++) {
			if (s.charAt(i) != s.charAt(len - i - 1)) {
				return false;
			}
		}
		return true;
    }
}
```