用的暴力法，超时了，卡在了特别长的一串a那个测试用例那里，于是等第n个字符不和第1个字符相同时，再开始比较：

```
class Solution {
    public String lastSubstring(String s) {
        char[] chars = s.toCharArray();
        char firstChar = chars[0];
        int firstCharCount = 1;
        int start = 0;
        int length = 0;
        char maxChar = '0';
        for (int i = 1; i < chars.length; i++) {
            if (chars[i] == firstChar && i == firstCharCount) {
                firstCharCount++;
                continue;
            }
            if (chars[i] > maxChar) maxChar = chars[i];
            if (chars[i] == maxChar) {
                if (compare(chars, i, chars.length - i, start, length) > 0) {
                    start = i;
                    length = chars.length - i;
                }
            }
        }
        if (compare(chars, 0, chars.length, start, chars.length - start) > 0) {
            return s;
        }
        return s.substring(start);
    }
    private int compare(char[] chars, int aStart, int aLength, int bStart, int bLength) {
        int result = 0;
        int count = Math.min(aLength, bLength);
        for (int i = 0; i < count; i++) {
            result = chars[aStart + i] - chars[bStart + i];
            if (result != 0) break;
        }
        if (result == 0 && aLength > bLength) result = 1;
        return result;
    }
}
```

执行用时 :13 ms, 在所有 Java 提交中击败了86.54%的用户
内存消耗 :41.3 MB, 在所有 Java 提交中击败了100.00%的用户
