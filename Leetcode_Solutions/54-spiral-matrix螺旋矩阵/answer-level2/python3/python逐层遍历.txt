**思路：**
看这位同学的思路吧，很简单
https://leetcode-cn.com/problems/spiral-matrix/solution/luo-xuan-ju-zhen-by-liao-tian-yi-jian/

**代码：**
```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix: return []
        m = len(matrix)
        n = len(matrix[0])
        layer_num = (min(m, n)+1) // 2  # 总共有多少层
        res_list = []  # 保存结果
        for lr in range(layer_num):
            start = lr  # 该层左上角的位置(start, start)
            last_col = n-lr-1  # 该层最后一列的索引
            last_row = m-lr-1  # 该层最后一行的索引
            
            for c in range(start, last_col+1):  # from left to right
                res_list.append(matrix[start][c])
            for r in range(start+1,last_row+1):  # from top to bottom
                res_list.append(matrix[r][last_col])
                
            if last_row != start and last_col != start:
                for c1 in range(last_col-1, start-1, -1):  # from right to bottom
                    res_list.append(matrix[last_row][c1])
                for r1 in range(last_row-1, start, -1):  # from bottom to top
                    res_list.append(matrix[r1][start])
        return res_list
```
