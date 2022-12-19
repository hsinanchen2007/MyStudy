该题的意思通俗理解是：给你这个3x3，或4x4或5x5等的数组(大列表套小列表)，每一行(每个小列表)中取一个最大值，构成一个列表A，每一列(每个小列表同一位置)比较取出一个最大值,构成一个列表B，以A为纵行，B为横行，排列好后
设A=[a,b,c,d,e] B=[h,i,c,j,k],AB中又一个数是原来数组中同一个位置的
```
grid = [ [    a    ],
         [    b    ],
         [h,i,c,j,k],
         [    d    ],
         [P   e    ] ]

```
然后空白处填上的数P不能大于P所在的那一列那一行的数
每个都填上后构成的新数组**S_grid的元素之和**比**之前grid数组之和增加了多少**


class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ud = []     # 竖直方向的每一列最大的数
        lr = []     # 水平方向的每个小列表最大的数
        s = len(grid)   # 第一次写没注意是任意长度的这种列表
        for i in range(s):
            grep = []   
            for j in range(s):
                grep.append(grid[j][i])     # 取出每个小列表里的同一个索引的数
            ud.append(max(grep))            # 取最大值
        for k in range(s):
            lr.append(max(grid[k]))         
        result = 0
        for i in range(s):
            for j in range(s):
                num = min(lr[i],ud[j]) - grid[i][j]     # 每个位置的数能取的最大值减掉该位置的数
                # lr = [8794]
                # ud = [9487]
                result += num       
        return result