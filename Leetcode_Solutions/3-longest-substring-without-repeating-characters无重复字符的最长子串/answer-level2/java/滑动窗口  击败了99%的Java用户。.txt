维持一个左子针left和一个右子针right。right-left就是无重复子串的长度。遍历规律为，

没有重复的话，right向右移动一位。

有重复的话，left右移并更新最长字符串max的值，右移一直到滑动窗口内无重复字符。即tmp[s.charAt(r)] == 0
更多滑动窗口相关的问题[参考这里](https://blog.csdn.net/reed1991/article/details/98799744)

```
public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int[] tmp = new int[256];
        int maxlen = 0;
        int l = 0;
        int r = 0;

        while (l < s.length()) {
            if (r < s.length() && tmp[s.charAt(r)] == 0) {
                tmp[s.charAt(r++)] = 1;
            } else {
                maxlen = maxlen > (r - l) ? maxlen : (r - l);

                tmp[s.charAt(l++)] = 0;

            }
        }

        return maxlen;

    }
```
### [更多leetcode题解点击此处](https://github.com/reedfan/leetcode/blob/master/leetcode.md)