### 解题思路
同习题 [面试题 01.08. 零矩阵](https://leetcode-cn.com/problems/zero-matrix-lcci/)
类似习题 [289. 生命游戏](https://leetcode-cn.com/problems/game-of-life/)


为了不利用额外的空间，分析如下
1. 利用空间 O(mn)
2. 利用空间 O(m+n) 只记录对应的行列下标
3. 利用空间 O(1)： 设置一个标志字符，对 python, 可以设置字符串， object()。但对于 java 语言强类型，标志位必须是 int, 可以采用查找[41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)来做,可能会出问题，例如矩阵中所有 int 值都出现过一次。
4. 将是否置零记录在矩阵的第0行，第0列的对应位置上。

细节1：由于 matrix[0][0] 标志位既代表了 row[0] 又代表了 column[0], 定义两个变量额外处理
细节2：后续对矩阵置零，对第0行和第0列的置零，应该在最后再进行，因为先做了，就会修改了标志位，可能导致矩阵全为 0

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        ## 同习题 [面试题 01.08. 零矩阵](https://leetcode-cn.com/problems/zero-matrix-lcci/) 可以看其题解
        # 先置为 -1， 最后在全部变为 0， 但这样如果原矩阵有一个 -1 就会尴尬 # x = object()  # 设为标志对像
        # 也有另一个做法，不用额外空间，标记 第 i 行，第 j 列
       
        m, n = len(matrix), len(matrix[0])
            
        # i =0   # 由于 matrix[0][0] 标志位既代表了 row[0] 又代表了 column[0], 定义两个变量额外处理
        row_0 = 1
        for j in range(n):
            if matrix[0][j] == 0:
                row_0 = 0
        # j = 0
        column_0 = 1
        for i in range(m):
            if matrix[i][0] == 0:
                column_0 = 0
    
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        ## 赋值 0
        # if column_0 == 0:# BUG: 这应该放到下面，因为这里修改了matrix[i][0], matrix[0][j], 而下面要用这个变量
        #     for i in range(m):
        #         matrix[i][0] = 0
        # if row_0 == 0:
        #     for j in range(n):
        #         matrix[0][j] = 0
        
        for i in range(1, m):
            if matrix[i][0] == 0:
                for j in range(n):
                    matrix[i][j] = 0
        
        for j in range(1, n):
            if matrix[0][j] == 0:
                for i in range(m):
                    matrix[i][j] =0
        if column_0 == 0:# BUG: 这应该放到下面，因为这里修改了matrix[i][0], matrix[0][j], 而下面要用这个变量
            for i in range(m):
                matrix[i][0] = 0
        if row_0 == 0:
            for j in range(n):
                matrix[0][j] = 0

```