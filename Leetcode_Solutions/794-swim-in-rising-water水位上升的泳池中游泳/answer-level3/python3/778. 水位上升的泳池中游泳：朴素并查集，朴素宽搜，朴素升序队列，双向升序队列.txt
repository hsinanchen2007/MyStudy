**方法一：并查集**

虽然大家都在吐槽TAG里的并查集，但直接并查集也不是不能做，最快也有240ms这样。

并查集初始化是二维数组，然后对所有点的高度进行排序，然后从低到高加入点检验并查集，如果两个对角的元素处于同一集合就返回答案。

因为在放宽时间条件的情况下，并查集是可以共用的，添加新点的时候集合路径已经被压缩了，所以时间复杂度还是可以接受，如果用二分查找目标时间来做的话还能再降一点时间复杂度，不过就麻烦多了。

```python
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        p = [[(i, j) for j in range(n)] for i in range(n)]                          #并查集二维数组初始化
        h = sorted([[grid[i][j], i, j] for j in range(n) for i in range(n)])        #按高度对点排序
        def f(a, b):
            if (a, b) != p[a][b]:
                p[a][b] = f(*p[a][b])       #二元并查集，元组传参要用*解包
            return p[a][b]
        k = 0
        for t in range(max(grid[0][0], grid[-1][-1]), h[-1][0]):        #起点是两个对角的最大值，终点是整个数据里的最大高度
            while h[k][0] <= t:
                _, i, j = h[k]
                for x, y in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
                    if 0 <= x < n and 0 <= y < n:
                        if grid[i][j] <= t and grid[x][y] <= t:
                            (pi, pj), (px, py) = f(i, j), f(x, y)
                            if (pi, pj) != (px, py):     #让符合时间空间条件且不相同的集合合并
                                p[px][py] = (pi, pj)
                k += 1
            if f(0, 0) == f(n - 1, n - 1):      #首末元素属于同一个集合就返回答案
                return t
        return h[-1][0]
```

**方法二：宽搜BFS**

直接宽搜，就是按时间从小到大来扩地图，比较纯粹好理解，时间也还行，最快180ms。

和Dijkstra略有区别，反倒是跟并查集的原理有点像，但也不是传统的递归或数据结构式的并查集。

当然，这里的确实可以用升序队列来优化。

```python
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        c = {(0, 0)}            #访问标记
        for t in range(max(grid[0][0], grid[-1][-1]), sys.maxsize):     #从首末元素的最大时间作为最开始的判断条件
            p = c.copy()        #宽搜队列初始化，每个时间点的初始状态是上一轮时间访问标记过的坐标
            while p:
                q = set()       #下一批宽搜队列
                for i, j in p:
                    if i == j == n - 1:     #如果走到目标了就返回时间
                        return t
                    for x, y in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
                        if 0 <= x < n and 0 <= y < n and grid[x][y] <= t and (x, y) not in c:#符合时空条件就扩散地图
                            q |= {(x, y)}
                            c |= {(x, y)}
                p = q           #队列传递
```

**方法三：升序队列**

本质上是就是朴素宽搜的优化版，让宽搜队列每次都能先扩展最小的点，最快120ms。

```python
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        b = {(0, 0)}                    #访问标记
        p = [[grid[0][0], 0, 0]]        #升序队列初始化
        t = 0                           #途径最大时间标记
        while True:
            h, i, j = p.pop(0)
            t = max(t, h)
            if i == j == n - 1:     #找到终点就就返回时间
                return t
            for x, y in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
                if 0 <= x < n and 0 <= y < n and (x, y) not in b:
                    bisect.insort(p, [grid[x][y], x, y])        #二分插入
                    b |= {(x, y)}
```

**方法四：双向升序队列**

升序队列的优化版，比单向的优先队列快一点点吧，最快108ms，但优化也不是那么明显，反正双向的写法就是复制粘贴改改值，也不差这一分钟。

```python
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        b, e = {(0, 0)}, {(n - 1, n - 1)}       #双向访问标记
        p, q = [[grid[0][0], 0, 0]], [[grid[-1][-1], n - 1, n - 1]]     #双向升序队列初始化
        t = 0       #途径最大时间标记
        while True:
            h, i, j = p.pop(0)
            t = max(t, h)
            if (i, j) in e:     #如果找到的点已经存在于另一个队列里，就返回答案
                return t
            for x, y in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
                if 0 <= x < n and 0 <= y < n and (x, y) not in b:
                    bisect.insort(p, [grid[x][y], x, y])
                    b |= {(x, y)}
            h, i, j = q.pop(0)      #从这里开始都是对称的，调换p，q，b，e就行。
            t = max(t, h)
            if (i, j) in b:
                return t
            for x, y in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
                if 0 <= x < n and 0 <= y < n and (x, y) not in e:
                    bisect.insort(q, [grid[x][y], x, y])
                    e |= {(x, y)}
```

![image.png](https://pic.leetcode-cn.com/f9828a49c6be823afd456a0cb0e2c1a42a91489c845cb0931313572e057c3342-image.png)
