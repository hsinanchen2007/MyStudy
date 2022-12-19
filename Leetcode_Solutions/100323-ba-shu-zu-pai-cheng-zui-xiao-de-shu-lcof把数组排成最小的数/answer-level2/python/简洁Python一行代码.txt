### 代码

```python3
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        return ''.join(sorted(map(str, nums),key=cmp_to_key(lambda x, y: int(x+y)-int(y+x))))
```