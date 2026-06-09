### 解题思路
单纯耿直的标记位置替换法
一如既往的单纯思路，想法只有三步

第一步：扫描整个矩阵，把等于0的元素的ij坐标分别记录下来
我的解法是把需要记录的i押进x_mark（list），j押进y_mark
因为添加了判断语句所以重复的i与j将只会被压入一次

第二步：替换行
循环存在x_mark中的所有元素，将每个元素对应的行都换成0

第三步：替换列
方法跟第二步类似
以上，思路一如既往的单纯耿直，若各位大佬有任何意见，望不吝赐教，十分感谢

### 代码

```python
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        x_max = len(matrix)
        y_max = len(matrix[0])
        x_mark = []
        y_mark = []

        for i in range(x_max):
            for j in range(y_max):
                if matrix[i][j] == 0:
                    if i not in x_mark:
                        x_mark.append(i)
                    if j not in y_mark:
                        y_mark.append(j)

        for i_zero_row in x_mark:
            for j_zero_row in range(y_max):
                matrix[i_zero_row][j_zero_row]=0
        for j_zero_col in y_mark:
            for i_zero_col in range(x_max):
                matrix[i_zero_col][j_zero_col]=0


```