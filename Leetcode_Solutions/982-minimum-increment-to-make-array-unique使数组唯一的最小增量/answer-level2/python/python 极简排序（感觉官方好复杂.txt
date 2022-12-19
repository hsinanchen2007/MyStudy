
记录上一步的值pre，当前值至少为pre+1

```python
class Solution:

    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        moves = 0
        pre = float('-inf')

        for num in A:
            if num <= pre:
                pre += 1
                moves += pre - num
            else:
                pre = num

        return moves

```

