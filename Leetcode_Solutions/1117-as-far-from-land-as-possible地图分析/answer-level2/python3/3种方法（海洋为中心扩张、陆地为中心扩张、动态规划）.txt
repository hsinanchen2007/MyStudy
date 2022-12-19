
## 解法一（海洋为中心扩张）
思路：以海洋区域坐标为中心点，向四周进行递归查找，其中最短距离的值即为当前海洋区域的距离，遍历所有海洋区域后，记录最大的距离。

为了减少单个海洋区域遍历时的重复递归，在递归中XY仅沿一个方向行走，因此最终划分为四个现象方向。

当前解法有种暴力法的味道，当然也可以添加访问标志，来进一步减少重复访问。

1. 仅对海洋区域为中心进行计算，忽略大陆区域
2. 单个现象的递归中，分别沿XY方向的递归，分别沿4个现象递归后的最小值即为当前海洋的距离
3. 对所有海洋中心遍历后，其中最大的距离即为解
* 时间复杂度：O(N^4^)
* 空间复杂度：O(1)

```python
# author: suoxd123@126.com
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        maxRst, MAX_TMP,  = 0, row + col
        tmpSum = sum([sum(v) for v in grid])
        if tmpSum in (0, row * col): #全是陆地或海洋
            return -1
        for i in range(0,row):
            for j in range(0,col):
                if grid[i][j] == 1:#忽略陆地区域
                    continue
                # 递归：计算单个海洋区域，在一个现象内的最近陆地距离
                def findDistance(rIdx, cIdx, rDelta, cDelta)-> int:                    
                    if not(0 <= rIdx < row and 0 <= cIdx < col): # 越界检查
                        return MAX_TMP
                    if grid[rIdx][cIdx] == 1:
                        return abs(rIdx - i) + abs(cIdx - j)
                    # 行、列方向分别拓展，取最小值
                    return min(findDistance(rIdx + rDelta,cIdx,rDelta , cDelta), 
                            findDistance(rIdx,cIdx + cDelta,rDelta , cDelta))
                minTmp = findDistance(i,j,1,1)#第一现象
                minTmp = min(minTmp,findDistance(i,j,-1,1)) #第二现象
                minTmp = min(minTmp,findDistance(i,j,-1,-1))#第三现象 
                minTmp = min(minTmp,findDistance(i,j,1,-1)) #第四现象
                maxRst = max(maxRst, minTmp)
        return maxRst
```

***
## 解法二（陆地为中心扩张）
思路：以陆地为中心向四周扩张，基于广度优先搜索的原理，以陆地为起点向四周扩张，直到所有地图都访问完，其中最大的距离即为解。

使用队列来实现广度优先搜索，也可以类似解法一中的递归实现。

1. 使用队列实现广度优先搜索算法，首先将全部陆地放入队列
2. 按照队列中元素，依次取出后向四个方向拓张，并记录距离的最小值，直到队列中元素清空为止
3. 扩张过程中，搜集所有地图坐标的距离最大值，即为所求
* 时间复杂度：O(N^2^)
* 空间复杂度：O(N^2^)
```python
# author: suoxd123@126.com
from queue import Queue
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        maxRst = 0
        visited = [[False] * col for k in range(0,row)]
        q = Queue()
        #全部陆地放入队列，作为搜索的起点
        for i in range(0,row):
            for j in range(0,col):                
                if grid[i][j] == 1:
                    q.put([i,j,0])
                    visited[i][j] = True
        # 计算单个海洋区域，一个邻居的距离
        def findDistance(rIdx, cIdx, val, rDelta, cDelta)-> int: 
            rIdx , cIdx = rIdx + rDelta, cIdx + cDelta
            if not(0 <= rIdx < row and 0 <= cIdx < col):#越界检查
                return
            if visited[rIdx][cIdx] == True:#不重复访问
                return
            visited[rIdx][cIdx] = True
            q.put([rIdx,cIdx,val + 1])
            nonlocal maxRst
            maxRst = max(val + 1,maxRst)
        while not q.empty(): #遍历整个队列
            r,c,v = q.get()
            findDistance(r,c,v,0,1) #上
            findDistance(r,c,v,0,-1)#下
            findDistance(r,c,v,-1,0)#左
            findDistance(r,c,v,1,0) #右
        return maxRst if maxRst > 0 else -1
```

***
## 解法三（动态规划）
思路：单个海洋区域的距离，等于四个方向距离的最小值，基于动态规划的思想，可以进行重复利用之前计算的值。由于XY方向会交叉影响，因此需要上下和左右进行联合循环，最终按照两个相反方向循环两次进行计算。
1. 基于地图构建初始距离，陆地为0，海洋为最大值
2. 对全部地图位置，求四个方向归集到中心的最小值
3. 查询所有地图上的最大距离值
* 时间复杂度：O(N^2^)
* 空间复杂度：O(N^2^)
```python
# author: suoxd123@126.com
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        maxRst, MAX_TMP,  = 0, row + col
        tmpSum = sum([sum(v) for v in grid])
        if tmpSum in (0, row * col): #全是陆地或海洋
            return -1
        rstList = [[0 if grid[k][v] == 1 else MAX_TMP for v in range(0,col)] for k in range(0,row)]
        #自左向右，自下往上
        for i in range(0,row):
            for j in range(0,col):
                if i >= 1: 
                    rstList[i][j] = min(rstList[i][j], rstList[i-1][j] + 1)
                if j >= 1:
                    rstList[i][j] = min(rstList[i][j], rstList[i][j-1] + 1)
        #自右向左，自上往下
        for i in range(row-1,-1,-1):
            for j in range(col-1,-1,-1):
                if i < row - 1: 
                    rstList[i][j] = min(rstList[i][j], rstList[i+1][j] + 1)
                if j < col - 1:
                    rstList[i][j] = min(rstList[i][j], rstList[i][j+1] + 1)

        maxRst = max([max(v) for v in rstList])
        return -1 if maxRst == MAX_TMP else maxRst
```

欢迎大佬们，随手关注VX公众号【[真相很简单](https://www.zhenxiangsimple.com/categories/tech/math/)】，拍砖指导，查看一题多解

![zhenxiangSimple](https://pic.leetcode-cn.com/f5cdcda21a37ab2959ff8c7fa75e174b326a0b126a27296ba28e906b7309dab1-zhenxiangSimple.jpg)