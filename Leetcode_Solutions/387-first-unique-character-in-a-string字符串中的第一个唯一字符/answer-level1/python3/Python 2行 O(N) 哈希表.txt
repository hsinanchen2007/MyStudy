```python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        d = {c: s.count(c) for c in set(s)}
        return ([i for i, c in enumerate(s) if d[c] == 1] + [-1])[0]
```
- 首先用字典 d 储存｛字符：出现次数｝，注意这里的字符来自 set，为了避免重复操作，防止TLE
- 用 list 记录 s 中出现次数为 1 的字符的索引
- 返回 list 第一个元素，如果原来的 s 中不存在出现次数为 1 的字符，则会返回后面添加的 [-1] 作为第一个元素