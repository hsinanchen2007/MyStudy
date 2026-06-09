### 解题思路
先初始化每行元素，之后利用动态规划实现累加运算

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        List = []
        for row_num in range(numRows):
            row = [None for _ in range(row_num+1)]
            row[0], row[-1] = 1, 1
            List.append(row)

        for i in range(2,numRows):
            for j in range(1,i):
                List[i][j] = List[i-1][j-1] + List[i-1][j]
        
        return List






```