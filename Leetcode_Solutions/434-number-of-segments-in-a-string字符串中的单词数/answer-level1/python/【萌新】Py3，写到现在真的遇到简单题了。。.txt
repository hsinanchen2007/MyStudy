### 解题思路
split函数秒解，不过这样还是用了很长时间和内存

### 代码

```python3
class Solution:
    def countSegments(self, s: str) -> int:
        s=s.split()
        return len(s)
```