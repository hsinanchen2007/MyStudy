### 解题思路
使用正则findall找到所有匹配项

### 代码

```python3
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        import re
        pattern = re.compile('[{}]'.format(J))
        return len(pattern.findall(S))
```