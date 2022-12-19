### 解题思路
学习大佬的写法，写的很好看
算法本身肯定就是回溯或者遍历加上剪枝，这个算法的剪枝做的不是很好，执行效率并不优秀
但是这种写法很pythonic，学习

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if target < 0 or len(candidates) <= 0:
            return []
        if target == 0:
            return [[]]
        return self.combinationSum(candidates[1:], target) + [[candidates[0]] + cp for cp in self.combinationSum(candidates, target - candidates[0])]
```