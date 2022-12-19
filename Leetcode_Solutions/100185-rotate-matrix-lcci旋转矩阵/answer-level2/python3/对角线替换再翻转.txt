### 解题思路
头一回这么好的成绩，记录一下哈哈
执行用时 :24 ms, 在所有 Python3 提交中击败了99.50%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了100.00%的用户

先将矩阵按对角线替换，发现和结果上下颠倒，那么再上下翻转即可。

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        length = len(matrix)
        for i in range(length):
            for j in range(length-1-i):
                matrix[i][j],matrix[length-1-j][length-1-i] = matrix[length-1-j][length-1-i],matrix[i][j]
        for i in range(length//2):
            matrix[i],matrix[length-1-i] = matrix[length-1-i],matrix[i]
```