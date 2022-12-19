# 思路
分别统计s和t中 各个字母出现次数。
再将相同字母的差值的绝对值累加，最后除以2即可。

# 代码
```java
class Solution {
    public int minSteps(String s, String t) {
        int[] char_s = new int[26], char_t = new int[26];
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            ++char_s[s.charAt(i) - 'a'];
            ++char_t[t.charAt(i) - 'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i)
            res += Math.abs(char_s[i] - char_t[i]);
        return res >> 1;
    }
}
```
