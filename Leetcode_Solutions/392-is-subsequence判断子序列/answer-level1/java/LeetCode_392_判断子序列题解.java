### 解题思路

倒序遍历字符串s，每次将t字符串中s的最后一个字母的位置拿出，并截取t，如果遍历能走完，则为true。否则为false。

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s != null && t != null && t.length() >= s.length()) {
            int tmp = 0;
            for (int i = s.length() - 1; i >= 0; i--) {
                if ((tmp = t.lastIndexOf(s.charAt(i))) != -1) {
                    t = t.substring(0, tmp);
                } else {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}
```