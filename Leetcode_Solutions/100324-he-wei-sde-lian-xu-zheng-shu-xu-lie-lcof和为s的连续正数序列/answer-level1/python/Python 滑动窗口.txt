```python
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        result, total, i, j = list(), 3, 1, 2

        while j + j - 1 <= target:
            if total > target:
                total, i = total - i, i + 1

            else:
                if total == target:
                    result.append(list(range(i, j + 1)))

                total, j = total + j + 1, j + 1

        return result
```
缺点是忘记判断target < 3的情况，但是题目要求了至少两个数，所以不判断也没啥问题。