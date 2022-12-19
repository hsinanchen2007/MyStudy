执行用时 :48 ms, 在所有Python3提交中击败了94.34% 的用户
内存消耗 :13.9 MB, 在所有Python3提交中击败了65.49%的用户
通过与行尾元素比较，确定可能存在的行，再在该行内遍历一次即可。

```
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = len(matrix)
        if matrix:
            for i in range(l):
                if matrix[i] and target <= matrix[i][-1]:
                    if target in matrix[i]:
                        return True
        return False
```