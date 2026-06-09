### 解题思路
定义一个最长字符串,遍历! 
一一对比二者的每一个字符,如果字符不相等{1,字符串长度相等时,继续比较不同次数}{2:字符串长度不等,将短的字符串索引--}
### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        // 二者最长
        String ls = first.length() > second.length() ? first : second;
        String ss = first.length() <= second.length() ? first : second;
        int abs = Math.abs(ls.length() - ss.length());
        if (abs > 1) {
            return false;
        }
        int a = 0;
        for (int i = 0, j = 0; i < ls.length(); i++, j++) {
            if (i == ls.length() - 1 && a == 0) {
                return true;
            }
            if (ls.charAt(i) != ss.charAt(j)) {
                if (ls.length() != ss.length()) {
                    j--;
                }
                a++;
            }
            if (a > 1) {
                return false;
            }
        }
        return true;
    }
}
```