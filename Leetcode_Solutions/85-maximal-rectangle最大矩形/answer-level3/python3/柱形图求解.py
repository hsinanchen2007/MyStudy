```
# 先转化为柱形图(每一层都可以转化为柱形图) --- 再求解最大面积
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # 每一行都可以转化为柱形图的值，将每一行变为84题的解法，最后求出全局最大值
        max_area = 0
        row = len(matrix)
        if row == 0:
            return 0
        column = len(matrix[0])
        # 将字符变为整型数据
        for i in range(row):
            for j in range(column):
                matrix[i][j] = int(matrix[i][j])
        max_area = max(matrix[0])
        # 统计每一行能形成的柱形图所对应的值，思想就是仿照84题解法
        for i in range(1, row):
            for j in range(column):
                if matrix[i][j] > 0:
                    matrix[i][j] = matrix[i-1][j] + 1
                    
        # 使用一个列表来存储每一行的值，为增加两个边界0           
        bar = []
        for i in range(row):
            bar = [0] * (column + 2)
            for j in range(column):
                bar[j+1] = matrix[i][j]
            # 开始求每一行能形成的最大面积   
            for i in range(1, len(bar)-1):
                if bar[i] > 0:
                    # 找左边界
                    for m in range(i-1, -1, -1):
                        if bar[m] < bar[i]:
                            left = m
                            break
                    # 找有右边界
                    for m in range(i+1, len(bar)):
                        if bar[m] < bar[i]:
                            right = m
                            break
                    # 计算当前值面积
                    curr = bar[i] * (right-left-1)
                    # 更新最大面积
                    if curr > max_area:
                        max_area = curr
        return max_area

```
