### 解题思路

归纳推理首选函数式编程，将问题分解成子问题，解决最小子问题就解决了整个问题。

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if target < 0 or len(candidates) <= 0:
            return []
        if target == 0:
            return [[]]
        return self.combinationSum(candidates[1:], target) + \
                [[candidates[0]] + cp for cp in self.combinationSum(candidates, target - candidates[0])]
```