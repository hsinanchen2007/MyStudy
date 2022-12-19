### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        for i in range(len(s)+1-k):
            if s[i:i+k]==s[i]*k: return self.removeDuplicates(s[:i]+s[i+k:],k)
        return s
```