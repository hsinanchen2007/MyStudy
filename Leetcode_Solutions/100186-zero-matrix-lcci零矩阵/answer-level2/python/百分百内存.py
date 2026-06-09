### 解题思路
怎么减少时间，求大佬指导
执行用时 :68 ms, 在所有 Python3 提交中击败了47.98%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了100.00%的用户
### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        nums = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    nums.append(i)
                    nums.append(j)
        for num in range(len(nums)):
            if num % 2 == 0:
                for j in range(len(matrix[0])):
                    matrix[nums[num]][j] = 0
            elif num % 2 == 1:
                for j in range(len(matrix)):
                    matrix[j][nums[num]] = 0
```