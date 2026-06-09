# 思路
2个字符串的**排列** **相等** -> 2个字符串 **各个字符** 的**个数**都**一一相等**。
比如`aabc`和`baca`这2个字符串的**排列**是**相等**的，都包含`2`个`a`、`1`个`b`、`1`个`c`。

题目求：`s2`是否包含`s1`的排列，也就是求证`s2`中是否**存在**1个**区间**，该**区间长度**为`s1.length()`(即`s1`字符串的长度)，且**该区间内** **各个字符** 的**个数**和`s1`**各个字符** 的**个数** 都**一一相等**。

既然区间长度是固定的(`s1.length()`)，则将该区间从`s2`的**最左端**滑动到**最右端**即可。
典型的动态滑窗问题。
也就是区间的位置从`[0, s1.length() - 1]`到`[s2.length() - s1.length() - 1, s2.length() - 1]`。

# 代码：
```java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int s1_len = s1.length(), s2_len = s2.length();
        if (s1_len > s2_len) return false;
        int[] s1_ch = new int[26], s2_ch = new int[26];
        for (int i = 0; i < s1_len; ++i) {
            ++s1_ch[s1.charAt(i) - 'a'];
            ++s2_ch[s2.charAt(i) - 'a'];
        }
        for (int i = s1_len; i < s2_len; ++i) {
            if (isEqual(s1_ch, s2_ch)) return true;
            --s2_ch[s2.charAt(i - s1_len) - 'a'];
            ++s2_ch[s2.charAt(i) - 'a'];
        }
        return isEqual(s1_ch, s2_ch);
    }

    private boolean isEqual(int[] s1_ch, int[] s2_ch) {
        for (int i = 0; i < 26; ++i)
            if (s1_ch[i] != s2_ch[i])
                return false;
        return true;
    }
}
```
