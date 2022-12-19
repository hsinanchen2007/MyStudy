## [更多双指针请参考](https://blog.csdn.net/reed1991/article/details/55096982)


```
public void reverseString(char[] s) {
        if (s == null || s.length < 2) {
            return;
        }
        int left = -1;
        int right = s.length;
        while (++left < --right) {
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
        }

        return;
    }
```
### [更多leetcode题解点击此处](https://github.com/reedfan/leetcode/blob/master/leetcode.md)