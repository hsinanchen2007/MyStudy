### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        for k,v in enumerate(A):
            if k == v:
                return k
        return -1
```