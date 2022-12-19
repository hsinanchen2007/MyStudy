### 解题思路
先排序，再取值

### 代码

```

class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        if not k:
            return []
        return arr[:k]

```