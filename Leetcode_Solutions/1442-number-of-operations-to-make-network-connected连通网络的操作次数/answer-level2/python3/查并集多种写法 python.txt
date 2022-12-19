quick-union算法：
```
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        linenums = len(connections)
        if n > linenums + 1:return -1

        idx = [i for i in range(n)]
        count = n

        def find(x):
            while idx[x] != x:
                x = idx[x]
            return x
        
        for i in range(linenums):
            p, q = connections[i]
            rootp = find(p)
            rootq = find(q)
            if rootp == rootq:
                continue
            idx[rootp] = rootq
            count -= 1
        
        return count-1

```

加权quick-union算法：改进的quick-union
```
代码块class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        linenums = len(connections)
        if n > linenums + 1:return -1

        idx = [i for i in range(n)]
        siz = [1 for i in range(n)]
        count = n

        def find(x):
            while idx[x] != x:
                x = idx[x]
            return x
        
        for i in range(linenums):
            p, q = connections[i]
            rootp = find(p)
            rootq = find(q)
            if rootp == rootq:
                continue
            if siz[rootp] > siz[rootq]:
                idx[rootq] = rootp
                siz[rootp] += siz[rootq]
            else:
                idx[rootp] = rootq
                siz[rootq] += rootp
            count -= 1
        
        return count-1
```

最优算法：带路径压缩的quick-union算法
```
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        linenums = len(connections)
        if n > linenums + 1:return -1

        idx = [i for i in range(n)]
        siz = [1 for i in range(n)]
        count = n

        def find(x):
            if idx[x] != x:
                idx[x] = find(idx[x])
            return idx[x]
        
        for i in range(linenums):
            p, q = connections[i]
            rootp = find(p)
            rootq = find(q)
            if rootp == rootq:
                continue
            if siz[rootp] > siz[rootq]:
                idx[rootq] = rootp
                siz[rootp] += siz[rootq]
            else:
                idx[rootp] = rootq
                siz[rootq] += rootp
            count -= 1
        
        return count-1

执行用时 :660 ms
```

详细解释可参考我的知乎文章[https://zhuanlan.zhihu.com/p/102456069]()