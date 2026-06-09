### 解题思路
此处撰写解题思路
sdict is used to save all the unique chars in s. The key is unique char, and the value is the last time appeared in the s as we are going through s. 
### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        sdict = {}
        slen = len(s)
        left = 0
        j = 0
        for j in range(slen):
            if s[j] in sdict and sdict[s[j]] >= left:  
                max_len = max(max_len, j-left)
                left = sdict[s[j]]+1
            sdict[s[j]] = j
            j += 1
        max_len = max(max_len, j-left)
        return max_len
            

```