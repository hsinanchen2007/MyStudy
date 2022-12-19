### 解题思路
我这里思路就比较笨一点：
1）找出腐烂的橘子，没有腐烂的就看有没有正常橘子，如果有正常橘子那么返回-1，如果没有正常橘子那么返回0，这里需要细品一下
2）循环第一轮的烂橘子，判断四个正方向是否有正常橘子，如果有的话，把坐标放到一个临时list里，注意要判断一下是否数组越界
3）在2）临时list里，存放的是第二轮要遍历的烂橘子坐标，再次判断四个正方向是否有正常橘子，把坐标放到一个临时list里
4）在3）临时list里，存放的是第三轮要遍历的烂橘子坐标，依次类推，直到四个正方向都没有橘子了
5）最后，还是要检查是否有正常的橘子，如果有的话说明无法全部腐烂

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = 0
        directons = [[1 , 0],[-1 , 0],[0 , 1],[0 , -1]]
        row = len(grid)
        col = len(grid[0])
        badList = []
        oneNum = 0

        #找到烂橘子的位置
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 2:
                    badList.append([i, j])
                elif grid[i][j] == 1:
                    oneNum += 1

        if len(badList) == 0:
            if oneNum == 0:
                return 0
            else:
                return -1    
        
        while badList:
            arr = []
            flag = False
            for i in badList:
                x = i[0]
                y = i[1]
                for direction in directons:
                    x1 = x + direction[0]
                    y1 = y + direction[1]
                    if 0 <= x1  < row and 0 <= y1 < col:
                        if grid[x1][y1] == 1:
                            arr.append([x1 , y1])
                            flag = True
                            grid[x1][y1] = 2
            badList = arr
            if flag == True:
                m += 1

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    return -1

        
        return m

    

```