### 解题思路
利用排序数组本身作为map，m + idx为key。
已知若不重复，value总大于等于key。
若A[idx]小于key值，则数字重复，需要累加至其值等于key值。
若A[idx]大于key值，则数字不重复，为了保证之后的数字不重复，更新后面数字的key值。
执行用时 :352 ms, 在所有 Python3 提交中击败了91.95% 的用户
内存消耗 :18.8 MB, 在所有 Python3 提交中击败了15.38%的用户

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: 'List[int]') -> 'int':
        if len(A) <= 1: return 0

        A.sort()
        m = A[0] - 0
        inc = 0
        for idx in range(1, len(A)):
            if A[idx] < m + idx:
                inc += m + idx - A[idx]
            elif A[idx] > m + idx:
                m = A[idx] - idx
        return inc
```