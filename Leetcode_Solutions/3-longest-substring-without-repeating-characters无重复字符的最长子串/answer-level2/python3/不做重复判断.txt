### 解题思路
基于最暴力的检查字段是否重复，发现已经遍历过的字符，已经知道到哪里是重复的，所有取最长字段就好

### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_len = 0
        now = {}
        now_len = 0
        index = 1
        st = 1
        for i in s:
            if i in now:
                st0=st
                st = now[i]+1
                ss=s[st0-1:st-1]
                for i1 in ss:
                    del now[i1]

                if now_len > max_len:
                    max_len = now_len
                
                now[i] = index
                now_len = len(now)
                index += 1

            else:
                now[i] = index
                index += 1
                now_len += 1
        if now_len > max_len:
            max_len = now_len

        return max_len

```