### 解题思路
使用了三种思路来解题，这题的关键是如何处理行和列的变化情况。我在初始解题的时候，没有办法保证一个变，一个不变。这里提供了两种不同的方法处理变化情况。一种是分按照向、下、左、上的顺序分别写4个循环，一次控制一个变量的变化。另外一种将这种变化量化为1，0，-1，代表增加、不变、减少。

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        '''
        方法三：模拟螺旋旋转，将矩阵看作是由不同大小的同心矩阵组成，从外到内，每次遍历一个。
        在遍历每一个矩阵的时候，分为四步：
        1.向右遍历，行数不变，列数增加1, r, c=[0:len(matrix[0])-1]。
        2.向下遍历，行数增加1，列数不变, r = [r+1: len(matrix)-1], c = len(matrix[0])-1。
        3.向左遍历，行数不变，列数减少1, r = len(matrix)-1, c = [len(matrix[0])-2:0:-1]
        4.向上遍历，行数减少1，列数不变, r = [len(matrix)-2:0:-1], c = 0。
        以上4步由4个for循环实现，放于一个函数内，遍历不同的矩阵，只需在主函数中传入不同的初始行、列数即可，即每个矩阵的左上角坐标ul(x0,y0), 右下角坐标dr(x1, y1)。
        '''
        if not matrix: return []
        # initializet the original ul, dr coordinates and ans.
        ans = []
        ul = [0,0]
        dr = [len(matrix)-1, len(matrix[0])-1]
        while ul[0] <= dr[0] and ul[1] <= dr[1]:
            # loop over all elments in the matrix in order
            for r, c in self.helper(ul, dr):
                ans.append(matrix[r][c])
            ul[0] += 1; ul[1] += 1
            dr[0] -= 1; dr[1] -= 1
        
        return ans
    
    def helper(self, ul_coords, dr_coords):
        # go right
        for c in range(ul_coords[1], dr_coords[1]+1):
            yield ul_coords[0], c
        # go down
        for r in range(ul_coords[0]+1, dr_coords[0]+1):
            yield r, dr_coords[1]
        # ensure the ul-coordinates less than the dr-coodinates
        if ul_coords[0] < dr_coords[0] and ul_coords[1] < dr_coords[1]: 
            # go left
            for c in range(dr_coords[1]-1, ul_coords[1], -1):
                yield dr_coords[0], c
            # go up
            for r in range(dr_coords[0], ul_coords[0], -1):
                yield r, ul_coords[1]





        '''
        # 28 ms	13.6 MB
        方法二：达到边界条件后，转换方向。这个方法是我最先想到的方法，但是在代码实现过程中，我发现无法在while循环中实现对行数和列数的变化，虽然变化有一定的规律，但是行数和列数是增加、减少同时发生，我不知道怎么实现，查看了官方答案，只觉得方法巧妙。
        ps：不同的人真是有共性的，能想到的解决方法都差不多，能看到自己的疑惑被解决的感觉真好。
        在该方法中，
        1.使用used数组来标记已经访问过的元素（为什么这么做？这是我从一到动态规划的题中学来的，那道题是探索最佳路径，每次可以向上下左右四个方向走，而这道题是一条路走到黑然后再还方向，我最初试图找到状态转移方程，但是没找到。）.
        2.之后为了解决行数、列数的变化问题，将其变化规律用两个数组表示出来，分别是：dr = [0,1,0,-1]（ 0表示行数不变，1表示增加行数，-1表示见减少行数，你可以根据题目要求想象一下遍历的过程，你会发现，行数和列数的变化情况和数组中定义的一致。），dc = [1,0,-1,0].
        3.r,c 表示上一步访问的行号和列号，cr, cc 表示当前访问的行号和列号（current row）。
        4.di控制行、列的当前方向
        
        if not matrix: return []
        # initialize the Row, Col, used, ans, dr, dl, r, c, di
        Row, Col = len(matrix), len(matrix[0])
        used = [[False] * Col for _ in range(Row)]
        ans = []
        dr = [0,1,0,-1]
        dc = [1,0,-1,0]
        r = c = di = 0
        
        # loop over all items in the matrix
        for _ in range(Row * Col):
            ans.append(matrix[r][c])
            used[r][c] = True
            cr, cc = r + dr[di], c + dc[di]
            if 0 <= cr < Row and 0 <= cc < Col and  not used[cr][cc]:
                r, c = cr, cc
            
            # reach the end of a row or a col, it's the time to change the direction
            else:
                di = (di + 1) % 4
                r, c = r + dr[di], c + dc[di]
        
        # return the answer
        return ans
        '''

        '''
        方法一：模拟旋转，弹出一行，将矩阵逆时针旋转一下，将待取列变成行，行变成列,推荐理解方法是，先明白代码中每个函数的作用，之后自己在纸上画画，旋转一下纸。
        # 60 ms	13.5 MB
        这里用到了python的内置函数zip（*）和map（），以及list（）。list（）函数是将传入的序列对象变为列表，map（规则，序列）函数是将某一规则应用到序列上，zip（*_）是解压过程（相当于zip（）的逆过程）,*后面传递是一个对象，这个对象的形状与zip（a,b）处理后的对象形状一致。举个例子来说，加上*传递一个二维列表，不加，需要传递进去两个一维列表。
        具体zip（*）用法可以参考：
        https://blog.csdn.net/weixin_38715680/article/details/104963841
        
        res = []
        while matrix:
            res += matrix.pop(0)

            # construct a new matrix
            matrix = list(map(list, zip(*matrix)))[::-1]

        return res 
        '''


```