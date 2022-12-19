### 解题思路
使用列表推导式，再返回排序列表。

### 代码

```python3
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        return sorted([str(x) for x in range(1, n + 1)])
```