![image.png](https://pic.leetcode-cn.com/783bfb9c0b0bce65dcb8b3acdc9b873e5bf7bd7b4bc9abd3678a9f3764e909ed-image.png)


看到螺旋矩阵，想到的是按圈一圈一圈的打印元素
那么就可以考虑循环打印的终止条件：

当rows和cols是奇数的时候，如图3x3，那么中间只会有一个数，每一圈我们只考虑左上角的index坐标设为start，那么第一圈是(0,0)，第二圈，也就是中间那一个数字的index是(1,1)
如果是4x4的矩阵，那么最内层会是一个圈，最左上角的index仍然为(1,1)，
那么可以推导：当rows > startx2 and cols > satrtx2的时候，我们就继续打印下一圈

比如当5x5的时候，最内层的左上角index为(2,2)，6x6时仍为(2,2)

在知道了循环的终止条件的时候，就可以循环的打印每一圈的元素了：
```
        rows = len(matrix)
        cols = len(matrix[0])
        start = 0
        res = []

        # 有值的时候，就要去循环打印每一圈
        # 设定start=0，从第0圈开始，（因为矩阵的index）
        # 左上角的坐标的x=y即为(start, start)
        # 循环就要考虑循环结束条件：rows>start*2 and cols>start*2
        while rows > start * 2 and cols > start * 2:
            self.printCircle(matrix, rows, cols, start, res)
            start += 1
        return res
```

那么我们还需要实现一个按圈打印的函数：
按圈打印分为四步，1.从左往右，2.从上往下，3.从右往左，4.从下往上


那么就需要分别讨论一下这四步在什么情况下可以发生：
首先，起始位置为(start,start)，行的终止位置为`endY = rows - start - 1`，列的终止位置为`endX = cols - start - 1`
x和y对应坐标轴，能够代表是行和列的关系

1.从左往右：只要有传进来元素需要打印，那么这一步都必然会发生
![image.png](https://pic.leetcode-cn.com/80288b05ab003bc721e75b2a5d825cef1badcf06a61d505a2fbb2695355bbe35-image.png)
遍历范围为：`for i in range(start, endX+1)`

2.从上往下：能够从上往下，那么至少得有两行才能打印，那么就是终止行-start行>0
![image.png](https://pic.leetcode-cn.com/3eabf447a2aa45b45c61f3f723cf1862833cc24eab5c4048fdd5b34922e1b0e3-image.png)

遍历范围为：`for i in range(start+1, endY+1)`
start+1的原因是这一列的第一个元素已经作为第一行的最后一个元素打印过了

3.从右往左：那么至少得有两行两列，那么就是终止列-start列>0
![image.png](https://pic.leetcode-cn.com/a5c288a0eb2806b9ec67797e38df3f155e0d8f164ad48170a28fa291c229a52b-image.png)
遍历范围为：`for i in range(endX-1, start-1, -1)`，逆序打印
endX-1是因为这一行的最右一个元素已经作为上一步的最后一个元素打印过了

4.从下往上：那么至少得有三行两列，终止行-start行>1
![image.png](https://pic.leetcode-cn.com/36bf96184626c08e42711f16917d7813661c2b8ec92bbe04348f12b6434a51f8-image.png)
遍历范围为：`for i in range(endY-1, start, -1)`，逆序打印
start不减1是因为start的元素已经作为第一步的第一个元素打印过了

```
class Solution:
    # matrix类型为二维列表，需要返回列表
    """
    画图
    """
    def spiralOrder(self, matrix):
        # write code here
        if not matrix:
            return []

        rows = len(matrix)
        cols = len(matrix[0])
        start = 0
        res = []

        # 有值的时候，就要去循环打印每一圈
        # 设定start=0，从第0圈开始，（因为矩阵的index）
        # 左上角的坐标的x=y即为(start, start)
        # 循环就要考虑循环结束条件：rows>start*2 and cols>start*2
        '''
        因为偶数行列的矩阵，最中间会是4个元素，左上角的start就可以一圈打印完全
        但是奇数行列的矩阵，最中间会是一个1个元素，需要再单独打印一次
        如5x5，中间是2,2的坐标，6x6的矩阵，中间四个元素的最左上角也是2,2的坐标
        但如果7x7，那么中间会变成3,3的坐标，仍然是7>2*3
        那么可以设定条件为rows > start * 2 and cols > start * 2就继续打印'''
        while rows > start * 2 and cols > start * 2:
            self.printCircle(matrix, rows, cols, start, res)
            start += 1
        return res

    def printCircle(self, matrix, rows, cols, start, res):
        endX = cols - start - 1
        endY = rows - start - 1
        # 第一步：从左往右打印，只要有值就会触发
        for i in range(start, endX + 1):
            res.append(matrix[start][i])

        # 第二步：至少有两行，那么会触发从上往下打印：每一行的最后一个元素
        # 判断是否能进行第二步：终止行号-起始行号>0（至少有两行，才能从上往下打印）
        if endY - start > 0:
            '''start+1是因为第一步的时候第一行的最后一个元素，也是这一步的这一列的第一个元素已经被打印过了'''
            for i in range(start + 1, endY + 1):
                res.append(matrix[i][endX])

        # 第三步：至少有两列（但走到这里的前提仍是上一步的至少有两行），那么会触发从右往左打印： 每一列的最后一个元素
        # 判断是否能进行第三步：终止行号-起始行号>0 and 终止列号-起始列号>0
        # （至少有2行2列，才能从上往下打印之后再从右往左打印）
        if endY - start > 0 and endX - start > 0:
            '''
            从右至左打印：逆序
            endX-1是因为这一行的最后一个元素已经被上一步的最后一个元素打印过了
            '''
            for i in range(endX - 1, start - 1, -1):
                res.append(matrix[endY][i])

        # 第四步：至少要有三行（但走到这一步的前提是上一步的至少有两列，至少有两行包括在至少有三行里了）
        # 如果终止行数和起始行数相差大于1，且多列，那么会触发从下到上打印
        # start行
        # 判断是否能进行第四步：终止行号-起始行号>2 and 终止列号>起始列号
        # （至少有三行两列，才能从上往下打印之后再从右往左再从下往上打印）
        if endY - start > 1 and endX - start > 0:
            '''endY-1是因为这一列的最后一个元素已经被打印过了，但是start是不能到达的一个元素，是因为第一步就走过这个元素了'''
            for i in range(endY - 1, start, -1):
                res.append(matrix[i][start])
```

