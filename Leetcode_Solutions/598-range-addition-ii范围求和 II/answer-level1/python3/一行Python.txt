### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        return min(min(i[0] for i in ops),m) * min(min(j[1] for j in ops), n) if ops else m*n
```