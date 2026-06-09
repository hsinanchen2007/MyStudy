### 解题思路
1、处理特殊情况：①为空，返回0；②行数为1，则计算该行‘1’的个数，个数大于0则返回1；③列数为1，则计算该列‘1’的个数，个数大于0则返回1。
2、初始化辅助数组：第1行、第1列的值对应matrix的值，其余初始化为0。（辅助数组大小与输入矩阵相同，用于记录对应矩阵位置以该位置为正方形右下角时的最大边长）
3、状态方程：当matrix[i][j]为‘1’时，辅助数组对应位置更新，temp[i][j] = min(temp[i-1][j], temp[i][j-1], temp[i-1][j-1]) + 1。
解释如下：以matrix[i][j]为正方形右下角的正方形边长最大为，该位置左侧、右侧、左上角边长的最小值+1，可画图分析。

### 代码

```python3
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if matrix is []:
            return 0
        if len(matrix) == 1 and matrix[0].count('1') > 0:
            return 1
        if len(matrix) >= 1 and len(matrix[0]) == 1:
            count_1 = 0
            for i in range(len(matrix)):
                if matrix[i][0] == '1':
                    count_1 += 1
            return 1 if count_1 > 0 else 0
        # 初始化辅助数组，第1行、第1列的值对应matrix的值，其余初始化为0
        temp = []
        for i in range(len(matrix)):
            temp.append([])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i == 0:
                    temp[i].append(int(matrix[0][j]))
                else:
                    if j == 0:
                        temp[i].append(int(matrix[i][0]))
                    else:
                        temp[i].append(0)
        # 更新辅助数组
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] == '1':
                    temp[i][j] = min(temp[i-1][j], temp[i][j-1], temp[i-1][j-1]) + 1
        max_square = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                max_square = max(max_square, temp[i][j]**2)
        return max_square
```