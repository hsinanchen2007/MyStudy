### 解题思路
笨方法，列出全部情况。
执行用时 :4 ms, 在所有 Java 提交中击败了99.98%的用户
内存消耗 :39.8 MB, 在所有 Java 提交中击败了5.02%的用户

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        char[] chars = s.toCharArray();
        int x = 0;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == 'I') {
                if ((i < chars.length - 1 && chars[i + 1] == 'V') ||
                        (i < chars.length - 1 && chars[i + 1] == 'X')) {
                    x -= 1;
                } else {
                    x += 1;
                }
            } else if (chars[i] == 'V') {
                x += 5;
            } else if (chars[i] == 'X') {
                if ((i < chars.length - 1 && chars[i + 1] == 'L') ||
                        (i < chars.length - 1 && chars[i + 1] == 'C')) {
                    x -= 10;
                } else {
                    x += 10;
                }
            } else if (chars[i] == 'L') {
                x += 50;
            } else if (chars[i] == 'C') {
                if ((i < chars.length - 1 && chars[i + 1] == 'D') ||
                        (i < chars.length - 1 && chars[i + 1] == 'M')) {
                    x -= 100;
                } else {
                    x += 100;
                }
            } else if (chars[i] == 'D') {
                x += 500;
            } else if (chars[i] == 'M') {
                x += 1000;
            } else {
                return 0;
            }
        }
        return x;
    }
}
```