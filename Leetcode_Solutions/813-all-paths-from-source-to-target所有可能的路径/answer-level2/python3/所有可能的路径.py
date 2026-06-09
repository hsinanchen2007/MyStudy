大概方法就是从graph 的第一个数列开始，以这个数列的元素为路引（索引），找到下一个数列并记录索引，循环到下一个数列是空数列时停止，并将一连串的路引记录下来。

```
class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        r = [0]
        g_0 = graph[0]
        def func(g_0):
            for i in g_0:
                r.append(i)
                if not graph[i]:
                    res.append(r[:])
                func(graph[i])
                r.pop()
        func(g_0)
        return res
```
