![image.png](https://pic.leetcode-cn.com/9241422803c52b362dfe2544daa8f4e234dde0ad5c43b28356e36663d9c29d2b-image.png)

相当于寻找有向图内点和点的距离关系，并输出两个点的距离，两点距离是通过除法计算出来的。

在计算过程中一直保存着计算过的数字，自己的子节点就是自己的父节点，所以路径压缩了很多，宽搜能够相对快的找到最近的计算路径，使之实质具备了并查集的性质。

```python
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        d = collections.defaultdict(dict)           #图的初始化
        for (a, b), v in zip(equations, values):    #距离初始化
            if a not in d: d[a] = {a: 1}
            d[a][b] =  v
            if b not in d: d[b] = {b: 1}
            d[b][a] = 1 / v
        def f(a, b):
            if a not in d or b not in d:#不存在的元素，输出-1
                return -1.0
            elif b in d[a]:             #计算过的元素，直接输出
                return d[a][b]
            else:
                c = {a}                 #宽搜访问标记
                q = {a}                 #宽搜队列
                while q:
                    t = set()           #下一轮宽搜队列
                    for i in q:
                        for j in d[i]:
                            if j not in c:
                                if j not in d[a]:   #没有计算过的点就存一下值
                                    d[a][j] = d[a][i] * d[i][j]
                                    d[j][a] = 1 / d[a][j]
                                if j == b:
                                    return d[a][j]  #找到路径了就输出
                                t |= {j}
                                c |= {j}
                    q = t
                return -1.0             #两个数不存在路径
        return [f(a, b) for a, b in queries]
```
