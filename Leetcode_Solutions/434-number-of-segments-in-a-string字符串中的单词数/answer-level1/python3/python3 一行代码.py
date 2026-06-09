### 重要
split()--list按照空格分开
len--list/str······ 个数
### 代码

```python3
class Solution:
    def countSegments(self, s: str) -> int:
        return len(s.split())
```