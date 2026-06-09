### 解题思路
无思路，sorted(key=func)

### 代码

```python3
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        return sorted(list(range(1, n+1)),key = str)
```