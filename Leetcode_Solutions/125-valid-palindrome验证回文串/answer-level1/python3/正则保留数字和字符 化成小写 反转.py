### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s=="": return True
        from re import sub
        after_peel = sub("\W","",s.lower())
        return after_peel[::-1]==after_peel
        
```