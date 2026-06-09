# ### 解题思路
# 1. 借用 *map*，*zip* 一行代码直接顺时针反转
# 2. 上下对折，沿主对角线对折
# 3. 还可以不用 *map*，多此一举了😂

# ### 关于本题的兄弟
# - 有个题叫*螺旋矩阵*，就是emmm*蛇形数组* (可能这个名字听得多点)
# - 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
# ```
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
# ```
# 其实就可以用 *map*,*zip* 直接原地逆时针旋转，先拿走一行，再旋转一次，直到全拿完，然后 `return ans` 就好了
# 各位可以试试 *map*,*zip* 的妙用

# ### 代码

# ```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        # 2 法二
        n = len(matrix)
        if n > 1:
            matrix[:] = matrix[::-1]                                           # 上下翻转
            for i in range(n-1):
                for j in range(n):
                    if i != j and i < j:
                        matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]  # 沿主对角线翻折
            
        '''
        # 1 法一
        matrix[:] = list(map(list, zip(*matrix[::-1])))                        # 直接顺时针旋转
        
        # 3 
        matrix[::] = zip(*matrix[::-1])                                        # 只用 zip
        '''
# ```