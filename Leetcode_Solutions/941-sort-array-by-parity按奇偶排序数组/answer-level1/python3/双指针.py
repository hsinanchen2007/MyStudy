### 解题思路

经典的双指针解法
执行用时 :80 ms, 在所有 python3 提交中击败了99.54%的用户
内存消耗 :13.3 MB, 在所有 python3 提交中击败了99.59%的用户

### 代码

```python3
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        pre, after, l = 0, len(A) - 1, len(A) - 1
        while pre < after and pre < l:
            while pre < after and (A[pre] & 1) == 0:
                pre += 1
            while pre < after and A[after] & 1 == 1:
                after -= 1
            if pre < after:
                A[pre], A[after] = A[after], A[pre]
                pre += 1
                after -= 1
        return A
```