```java
class Solution {
    public int findLUSlength(String[] strs) {
        boolean[] flags = new boolean[strs.length];
        // 暴力，外层为父字符串
        for (int i = 0; i < strs.length; i++) {
            // 内层为子字符串
            for (int j = 0; j < strs.length; j++) {
                // 一旦子字符串是父子字符串的子序列，那么将子字符串标记扔掉。
                if (i != j && contains(strs[i], strs[j])) {
                    flags[j] = true;
                }
            }
        }
        int maxLen = -1;
        for (int i = 0; i < strs.length; i++) {
                // 找到一个不是子字符串的字符串
            if (!flags[i]) {
                // 判断长度.
                maxLen = maxLen > strs[i].length() ? maxLen : strs[i].length();
            }
        }
        return maxLen;
    }

    /**
     * 如果str1 是str 的子序列
     */
    private boolean contains(String str, String str1) {
        int i2 = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == str1.charAt(i2)) {
                i2++;
                if (i2 == str1.length()) {
                    return true;
                }
            }
        }
        return false;
    }
}

```
