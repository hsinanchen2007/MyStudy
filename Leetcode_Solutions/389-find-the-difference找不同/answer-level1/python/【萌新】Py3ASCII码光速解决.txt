### 解题思路
ASCII码和之差为增加字母的ASCII码

### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return chr(sum(map(ord, t)) - sum(map(ord, s)))
        
```