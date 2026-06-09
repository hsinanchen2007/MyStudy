## 解题思路

看到题解里 LighT 的题解“[二分图最大独立集](https://leetcode-cn.com/problems/maximum-students-taking-exam/solution/er-fen-tu-zui-da-du-li-ji-by-lightcml/)” 收获很大，所以我用 python 实现了一下，不同的地方是： 原方法使用了 Dinic 算法，我这用的更简单的 Ford-Fulkerson 算法。

然后建图的时候 python 会更加灵活，基本方法是：
额外定义一个源点，一个汇点。我的代码里给每个点编号了，源点固定是 0,汇点固定是 1。第一个 for 循环里会给图中，每个可以用的座椅从 2 开始编号。（cur 变量初始化为 2），然后在源点到所有偶数列的点连边。所有奇数列的点到汇点连边。（注意这个边是有向的）

![image.png](https://pic.leetcode-cn.com/4bfbf039a2e7530e29010159b7e7cd63f3639285b4cca6909b9afe5e408a52ea-file_1581558888184)
### 给每个点编号和与汇点、源点建立边的代码
```python
edges = [[], []]
s = 0
t = 1
cur = 2
for i in range(n):
    for j in range(m):
        if seats[i][j] == '.':
            edges.append([])
            if j & 1 == 1: # 偶数
                edges[s].append(cur)
            else:
                edges[cur].append(t)
            seats[i][j] = cur
            cur += 1
```
编号前：
```python
["#",".","#","#",".","#"]
[".","#","#","#","#","."]
["#",".","#","#",".","#"]
```
编号后：
```python
['#', 2, '#', '#', 3, '#']
[4, '#', '#', '#', '#', 5]
['#', 6, '#', '#', 7, '#']
```

编号完成并把源点连偶数列，奇数列连汇点，这个已经是一个二分图了。图是不联通的。
然后我们再把冲突（就是能看到别人答案的）座位两两连接，但是这个和谁能抄谁的没有关系，而必须是偶数列连接到奇数列。

简化以后的图是这样
![image.png](https://pic.leetcode-cn.com/fdbc34d5f14dd7203ec855d1d44697b4800e5ffbc866f53e5176c4f85783c914-file_1581558888192)

### 找反向边

虽然边是单向的，但是算法中有两种操作：
1. 增大边上的流（从一个点走正向边到另一个点）
2. 减少边上的流（从一个点沿着反向边到另一个点）

所以还要把反向边找出来

代码很简单，就是把 edges 里的边颠倒过来。

```python
edges2 = [[] for i in range(len(edges))]
for s, e in enumerate(edges):
    if s == 0: continue
    for i in e:
        if i == 1: continue
        edges2[i].append(s)
```

### 求最大流

一个 dfs 函数。每次寻找一条增广路径，直到找不到增广路径。

增广路径 就是一条从 s（编号 0） 到 t（编号 1） 的简单路径（简单路径就是无环）。
所以定义一个 vis 数组，标记是否到过某点，防止出现环。
```python
vis = [False] * len(edges)
```

因为这里每条边的流量都是 1。所以我们只定义一个二维矩阵，可以表示任意两个点之间现在是否有流量。
```python
flag = [[False] * len(edges) for _ in edges]
```
flag[i][j] 为 True 代表 i 到 j 有流量（当然得现有边才行），有流量就不能正向走，但可以反向走。没有流量则相反。

最后答案是 可用的座位数 - 最大流

## 代码

```python
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        n = len(seats)
        m = len(seats[0])
        edges = [[], []]
        s = 0
        t = 1
        cur = 2
        for i in range(n):
            for j in range(m):
                if seats[i][j] == '.':
                    edges.append([])
                    if j & 1 == 1: # 偶数
                        edges[s].append(cur)
                    else:
                        edges[cur].append(t)
                    seats[i][j] = cur
                    cur += 1
        if cur == 2: return 0
        for i in range(n):
            for j in range(m):
                if seats[i][j] != '#':
                    cur = seats[i][j]
                    if j + 1 < m and seats[i][j+1] != '#':
                        if j & 1 == 1:
                            edges[cur].append(seats[i][j+1])
                        else:
                            edges[seats[i][j+1]].append(cur)
                    if i > 0:
                        if j + 1 < m and seats[i-1][j+1] != '#':
                            if j & 1 == 1:
                                edges[cur].append(seats[i-1][j+1])
                            else:
                                edges[seats[i-1][j+1]].append(cur)
                        if j - 1 >= 0 and seats[i-1][j-1] != '#':
                            if j & 1 == 1:
                                edges[cur].append(seats[i-1][j-1])
                            else:
                                edges[seats[i-1][j-1]].append(cur)
        #for e in enumerate(edges): print(e)
        #for s in seats: print(s)
        edges2 = [[] for i in range(len(edges))]
        for s, e in enumerate(edges):
            if s == 0: continue
            for i in e:
                if i == 1: continue
                edges2[i].append(s)
            
        flag = [[False] * len(edges) for _ in edges]
        vis = [False] * len(edges)
        p = []
        ans = 0
        def dfs(i):
            #print(i)
            if i == 1:
                print('\t', p)
                return True
            for j, e in enumerate(edges[i]):
                if vis[e]: continue
                vis[e] = True
                if flag[i][e] == False:
                    flag[i][e] = True
                    p.append(e)
                    r = dfs(e)
                    p.pop()
                    if r:
                        vis[e] = False
                        return r
                    flag[i][e] = False
                vis[e] = False
            for j, e in enumerate(edges2[i]):
                if vis[e]: continue
                vis[e] = True
                # print(j, i)
                if flag[e][i] == True:
                    flag[e][i] = False
                    p.append(e)
                    r = dfs(e)
                    p.pop()
                    if r:
                        vis[e] = False
                        return r
                    flag[e][i] = True
                vis[e] = False
            return False

        while dfs(0):
            cur -= 1
        return cur - 1
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)