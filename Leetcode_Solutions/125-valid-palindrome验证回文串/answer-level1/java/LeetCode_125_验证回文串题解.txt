### 解题思路

题目很简单，说两个重点：

- 不能简单的决定偶数长度的字符串就不会回味串 = = 例如：abba, aa等
- 判断字符是不是数字应该是 `x >= '0' && x <= '9'` 而不是 ~~`x >= 0 && x <= 9`~~
- 在字符串刚开始全部转为小写，不要再循环里面转

### 代码

```java
class Solution {
public boolean isPalindrome(String s) {
        char[] str = s.toLowerCase().toCharArray();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length; i++) {
            if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z')) {
                sb.append(str[i]);
            }
        }
        return isPalindromeStr(sb.toString());
    }

    private boolean isPalindromeStr(String s) {
        if (s.length() <= 1) return true;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }

        return true;
    }
}
```