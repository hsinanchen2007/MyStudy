### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sumZero(self, n: int) -> List[int]:
        return [*range(1-n, n, 2)]
```