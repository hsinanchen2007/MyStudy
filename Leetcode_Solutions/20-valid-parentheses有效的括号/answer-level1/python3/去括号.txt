### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        while '{}' in s or '[]' in s or '()' in s:
            s = s.replace("{}",'')
            s = s.replace("[]",'')
            s = s.replace('()','')
        return s == ''
```