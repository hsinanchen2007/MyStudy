### 解题思路
len(最长不重复子串） = max（去掉最后一个字符的原最长不重复子串len, 包含最后一个字符的最长不重复字串len）

求出“包含最后一个字符的最长不重复字串len”


### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1
        
        def find_left(s, i):
            tmp = s[i]  #先取最后一个
            j = i - 1
            while j >= 0 and s[j] not in tmp:
                tmp += s[j]
                j -= 1
            return len(tmp) #包含最后一个字符在内的最长不重复子串 的长度

        length = 0
        for i in range(len(s)):
            length = max(length, find_left(s, i))
        return length
```