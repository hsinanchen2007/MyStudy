```python
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return chr(sum(map(ord, t)) - sum(map(ord, s)))
```
- 每一个字符都对应一个 ASCII 数字，那么那个不同的数字的 ASCII 码就等于 t 的所有字符码之和 - s 的
- ord 函数将单个字符转换为 ASCII 码， chr相反