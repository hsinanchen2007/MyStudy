### 解题思路
执行用时 :32 ms, 在所有 Python3 提交中击败了99.79%的用户
内存消耗 :17.7 MB, 在所有 Python3 提交中击败了100.00%的用户

不知道为什么时间消耗这么少，难道if判断不占时间吗？
### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            if target in row:
                return True
        return False
```