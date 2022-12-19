字符串从左开始遍历字母`i`。并把遍历后的结果放入新的变量中`new_s`。
然后在新字符串`new_s`中查看遍历字母`i` 是否有重复。
如果在新字符串`new_s`中出现重复。
那么截取新字符串`new_s`，去掉重复部分。
```
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        new_s = ''
        max_len = 0
        for i in range(0, len(s)):
            # 判断变量 i 中字符在 new_s 中是否有重复。有截取
            if s[i] in new_s:
                new_s = new_s[new_s.index(s[i]) + 1:]
            new_s += s[i]
            if len(new_s) > max_len:
                max_len = len(new_s)
        return max_len
```
