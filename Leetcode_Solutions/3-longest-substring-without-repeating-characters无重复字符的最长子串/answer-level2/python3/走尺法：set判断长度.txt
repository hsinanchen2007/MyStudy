### 解题思路
走尺法，start 是头，Length 是长度  只要Start+length 不超出字符长度就一直走下去，判断可以扩展的时候
length+1,不能扩招就Start+1

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        start = 0  #尺子开始
        length = 1 #尺子长度
        while ((start + length) < len(s)):
            if len(set(s[start:start + length+1])) == length+1:#判断尺子长度是否可以扩
                length += 1
            else:#不能扩   开始点就走一步
                start += 1
        return length
```