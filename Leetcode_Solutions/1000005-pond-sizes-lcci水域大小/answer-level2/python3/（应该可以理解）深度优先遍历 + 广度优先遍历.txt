# 1、广度优先遍历：
（1）将数组从左往右，从上往下进行遍历，当遇到一个数据是0，即表示海洋时，将该位置放进队列中；初始化一个变量nums，表示以该位置为起点的海洋面积有多大，初始值为nums=1；同时切记将当前位置的海洋的值从0改为-1，表示已经搜索过；
（2）遍历队列，对队列中的每个位置，判断其左上，上，右上，左，右，左下，下，右下八个位置是否是海洋，如果是海洋，则将其位置信息放进队列中，并使num的值加一；同时切记将其海洋值从0变为-1，表示其已经搜索过；
（3）当队列为空时，表示与当前位置相连的海洋已经寻找完毕，将得到的nums值放进一个列表中；这时候需要去寻找下一个点，重复上面（1）-（3）的操作，直到对整个地图搜索完毕；

具体Python代码如下：

```
class Solution:
    def pondSizes(self, land: List[List[int]]) -> List[int]:
        rows,cols = len(land),len(land[0])  # 计算行数和列数
        if rows==0 or cols==0:
            return []
        
        def neighbor(i,j):    # 用于寻找当前位置land[i][j]的周围所有数据中是否存在海洋，如果存在则返回其坐标信息
            for nr,nc in [[i-1,j],[i+1,j],[i,j-1],[i,j+1],[i-1,j-1],[i-1,j+1],[i+1,j-1],[i+1,j+1]]:
                if 0<=nr<rows and 0<=nc<cols and land[nr][nc]==0:
                    yield nr,nc
                    
        max_num = []    # 用于存储所有池塘的面积
        queue = collections.deque()   # 队列，用于广度优先遍历
        
        for i in range(rows):    #  遍历整个地图
            for j in range(cols):
                if land[i][j] == 0:    # 发现海洋点
                    queue.append([i,j])    # 将当前海洋位置放进队列中
                    land[i][j] = -1    # 将当前海洋的数据从0变为-1，表示已经搜索过
                    num = 1    # 当前海洋面积的大小为1
                    while queue:    # 遍历当前海洋的周围所有邻居的情况
                        nr,nc = queue.popleft()    
                        for ii,jj in neighbor(nr,nc):    #  使用上面定义的生成器函数    
                            land[ii][jj] = -1    # 找到l周围的海洋，并将其值变为-1，表示已经搜索过
                            queue.append([ii,jj])    # 将其放进队列中，用于下一步的广度优先遍历
                            num += 1    # 当其周围有一个海洋时，池塘的面积需要加1
                    max_num.append(num)      # 将当前位置的池塘面积大小放进队列中      
        return sorted(max_num)
                    
```


# 2、深度优先遍历
（1）将数组从左往右，从上往下进行遍历，当遇到land[i][j]=0时表示遇到海洋，基于land[i][j]遍历其周围所有的点。深度优先遍历和广度优先遍历不同，广度优先遍历使用队列，遍历时一圈一圈往外遍历。而深度优先遍历时当在某点周围遇到海洋点时，基于该海洋点再搜索周围的点，如果再找到则一直深究下去。

其Python代码如下：

```
class Solution:
    def pondSizes(self, land: List[List[int]]) -> List[int]:
        rows,cols = len(land),len(land[0])
        if rows==0 or cols==0:
            return []
        
        def neighbor(i,j):   #  用于遍历某点周围的所有点是否是海洋点
            for nr,nc in [[i-1,j],[i+1,j],[i,j-1],[i,j+1],[i-1,j-1],[i-1,j+1],[i+1,j-1],[i+1,j+1]]:
                if 0<=nr<rows and 0<=nc<cols and land[nr][nc]==0:
                    yield nr,nc
                    
        def dfs(i,j):    # 深度遍历函数
            area = 1
            land[i][j] = 1    # 修改已经遍历过的海洋点
            for nr,nc in neighbor(i,j):    # 对land[i][j]的周围进行遍历，找到海洋点
                area += dfs(nr,nc)    
            return area
                    
        max_num = []    # 用于存储不同的池塘面积
        
        for i in range(rows):    # 遍历整个地图
            for j in range(cols):
                if land[i][j] == 0:    # 遇到海洋点
                    max_num.append(dfs(i,j))    # dfs()函数返回以包括land[i][j]的池塘面积
        
        return sorted(max_num)    # 进行排序
```