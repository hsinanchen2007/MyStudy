### 解题思路
解题思路太简单了。

被0P坑了。
![WX20200322-234745.png](https://pic.leetcode-cn.com/b239da09b0874f1c2e3b1fc197e468fca621f18c58a3fd3a4828b8fc353c5f83-WX20200322-234745.png)

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0 || s.length() == 1) {
            return true;
        }
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            while (l < r && (s.charAt(l) == ' ' || !isAlphaNumeric(s.charAt(l)))) {
                l++;
            }
            while (l < r && (s.charAt(r) == ' ' || !isAlphaNumeric(s.charAt(r)))) {
                r--;
            }
            if (s.charAt(l) == s.charAt(r) ||
                    ((s.charAt(l) > 57 && s.charAt(r) > 57) // 这个判断不能少 0P就坑在这里
                            && (s.charAt(r) + 32 == s.charAt(l)
                            || s.charAt(l) + 32 == s.charAt(r)))) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }

    private boolean isAlphaNumeric(char c) {
        // 0 ~ 9 ascii码范围：48 ~ 57
        // A ~ Z ascii码范围：65 ~ 90
        // a ~ z ascii码范围：97 ~ 122
        if (c >= 48 && c <= 57) {
            return true;
        }
        if (c >= 65 && c <= 90) {
            return true;
        }
        if (c >= 97 && c <= 122) {
            return true;
        }
        return false;
    }
}
```