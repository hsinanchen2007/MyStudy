### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = 0
        for i in range(len(s)):
            result = []
            for w in range(i,len(s)):
                if s[w] not in result:
                    result.append(s[w])
                    count = max(count,len(result))
                else:
                    break 
                    
        return count 


```