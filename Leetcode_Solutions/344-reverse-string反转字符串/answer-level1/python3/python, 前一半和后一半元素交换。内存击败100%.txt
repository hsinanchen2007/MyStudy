### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = len(s)
        if n <=1:
            return s
        for i in range(n//2):
            s[i], s[n-1-i] = s[n-i-1], s[i]
        return s
            
```