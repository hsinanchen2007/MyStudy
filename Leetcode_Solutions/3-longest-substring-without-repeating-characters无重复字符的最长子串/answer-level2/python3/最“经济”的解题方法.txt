好像没看到有人用这种方法，思路是用两个标志位start和end截取出当前未重复的字符串，随着end不断向后移，当遇到和end指向位置和截取字符串相同是，向后移动start，直到没有重复字符串。
不多说，直接上代码，耗时64ms，内存消耗12.8M
时间复杂度：O(N)
几乎不额外占用空间：
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = len(s)
        start = 0
        end = 0
        max_len = 0
        cur_len = 0
        while(end < l):
            while s[end] in s[start:end]:
                start += 1
            cur_len = end - start + 1
            if (cur_len > max_len):
                max_len = cur_len
            end += 1
        return max_len
```
