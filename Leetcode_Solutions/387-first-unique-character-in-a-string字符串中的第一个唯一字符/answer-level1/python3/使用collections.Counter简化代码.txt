``` python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        # 对每个出现的字母计数
        s_counter = collections.Counter(s)
        
        # 找到只出现一次的最靠前的那个字母，找不到就返回-1
        for i in range(len(s)):
            if s_counter[s[i]] <= 1:
                return i
        else:
            return -1
```