### 解题思路
0. **要是我是面试官：N X M 90 翻转；； N X N的90度翻转**
1.  自行实现的是 注释的代码，输出结果对，但是不符合题意；可接任意N*M矩阵
    - 也是画了一下坐标的变化，双层循环，所有元素都遍历到
2. 原地翻转，仅仅适用于 N*N的方阵
    - **i <= (n-1) // 2;  i<=j < n-1-i **
    - 对于i 的取值，为什么是 (n-1) // 2，这和奇数偶数有关；至于为什么可以等于，可以通过画图得到
    - 对于j的取值，有序旋转，需要双向截断
    - **图形就是i 沿着主对角线前进，j 沿着i所在的正方形的左侧边移动**

3. 图解：对题目理解非常有帮助
    - i，j取值范围，注意python range 取 等号时
    - 每一组 i,j  寻找其他三个要变换的元素
    
        
![矩阵旋转.jpg](https://pic.leetcode-cn.com/b54a2a3a96cb64137bd54656711f2d78a99f2c8b608239e9a53fdec8011a80a3-%E7%9F%A9%E9%98%B5%E6%97%8B%E8%BD%AC.jpg)


4. **其它翻转 (N*M)的矩阵，都比90度翻转简单**
    - 同行翻转，即水平方向180度：swap(cur[i][j], cur[i][msize-1-j]), msize 表示多少列
    - 同列翻转，即垂直方向翻转180度：swap(cur[i][j], cur[nsize-1-i][j]),nsize 表示多少行
    - 列行变化：swap(cur[i][j], cur[j][i])
    - **逆时针翻转90度呢？**
        for i in range(mid+1):
            for j in range(i, n-1-i):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[j][n-1-i]
                matrix[j][n-1-i] = matrix[n-1-i][n-1-j]
                matrix[n-1-i][n-1-j] = matrix[n-1-j][i]
                matrix[n-1-j][i] = tmp 
                '''
                **## 顺时针90度的代码，图解完全一样，只是赋值顺序反着来了**
                matrix[i][j] = matrix[n-1-j][i]
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
                matrix[j][n-1-i] = tmp 
                '''




### 代码
        
```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        '''
        nsize = len(matrix)
        if nsize == 0:
            return matrix 
        msize = len(matrix[0])

        res = [[0] * nsize  for i in range(msize)]


        for i in range(nsize):
            for j in range(msize):
                res[j][nsize-1-i] = matrix[i][j]
        
        matrix = res 
        ## 此方法可输出正确结果,但是不合题意，需要额外o(N)空间
        ## 且适用于 N*M的任意矩阵
        '''
        if len(matrix) == 0 or len(matrix) != len(matrix[0]): ## N*N 
            return False
        
        n = len(matrix)
        mid = (n -1) // 2

        for i in range(mid+1):
            for j in range(i, n-1-i):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[n-1-j][i]
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
                matrix[j][n-1-i] = tmp 
        













```