### 解题思路
1. 先排序后取数
2. 可以利用快排的思想来做，需要判断递归处理的时候k是否大于取值得数，只要递归一半

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        return arr[:k]
```