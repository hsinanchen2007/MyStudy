### 解题思路
在多次的迭代中，只要可以完全匹配，那么一定能完全换成空字符串

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        while '{}' in s or '[]' in s or '()' in s:
            s = s.replace('[]','')
            s = s.replace('{}','')
            s = s.replace('()','')
        return s == ''

```