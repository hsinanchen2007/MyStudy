并查集的初始化就是每个点只属于自己标记的集合，即p[x]=x。

遍历边，如果两个点集合不同，那就合并进同一个集合，这里用了递归修改集合。

如果遍历边的过程中，发现两个点已经加进过之前的集合了，那就说明成环了，这时就可以输出了。

这就是传统并查集的做法。

```python []
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        p = [*range(len(edges) + 1)]      #并查集元素初始化
        def f(x):
            if p[x] != x:       #递归修改所属集合
                p[x] = f(p[x])
            return p[x]
        for x, y in edges:      #遍历边
            px, py = f(x), f(y)
            if px != py:        #检查集合，如果集合不同就合并
                p[py] = px
            else:
                return [x, y]   #集合相同就返回答案
```

原创的，非递归的并查集方法，比传统方法更短更快，空间复杂度依旧是$O(N)$。

```python []
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        p = [[i] for i in range(len(edges) + 1)]  #并查集初始化 
        for x, y in edges:
            if p[x] is not p[y]:    #如果两个集合地址不一样
                p[x].extend(p[y])   #合并集合
                for z in p[y]:
                    p[z] = p[x]     #修改元素集合标记的指针地址
            else:
                return [x, y]
```

```python []
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        p = {i: {i} for i in range(1, len(edges) + 1)}  #并查集初始化 
        for x, y in edges:
            if p[x] is not p[y]:    #如果两个集合地址不一样
                p[x] |= p[y]        #合并集合
                for z in p[y]:
                    p[z] = p[x]     #修改元素集合标记的指针地址
            else:
                return [x, y]
```

新方法拿到的100%

![image.png](https://pic.leetcode-cn.com/57f25997d01e64acfba06fb01ba46fddb8359651364ab6f8a97ccc8f66863c15-image.png)

优化了权重以后可以达到24ms，再快一倍。

```python []
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        p = [[i] for i in range(len(edges) + 1)]  #并查集初始化 
        for x, y in edges:
            if p[x] is not p[y]:            #如果两个集合地址不一样
                if len(p[x]) < len(p[y]):   #权重优化判断
                    x, y = y, x
                p[x].extend(p[y])           #合并集合
                for z in p[y]:
                    p[z] = p[x]             #修改元素集合标记的指针地址
            else:
                return [x, y]
```

![image.png](https://pic.leetcode-cn.com/2b00a3f1d58c9df9e758f7d153e73b70c7ac6738d8e79bbb355340bdcf1756b5-image.png)
