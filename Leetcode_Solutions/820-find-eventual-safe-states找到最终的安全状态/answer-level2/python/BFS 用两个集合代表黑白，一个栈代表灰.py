判断是否有环，如果有环，则前趋节点都记为不合法的点；
同样的，如果碰到有后继是不合法的，也将其，及其前缀放入不合法的点中；
如果碰到无后继节点，则将其加入black中。

最后输出black和white的并集即可

```python
class Solution(object):
    def eventualSafeNodes(self, graph):
        # 初始化
        n = len(graph)
        white = set(range(1, n))
        gray = [0]
        black = set()
        invalid = set()
        # DFS
        cur = 0
        while gray:
            cur = gray[-1]
            if not graph[cur]:
                black.add(gray.pop())
                if not white:
                    while gray:
                        temp = gray.pop()
                        if temp in graph[temp]:
                            invalid.add(temp)
                            continue
                        if not (set(graph[temp]) & invalid):
                            black.add(temp)
                    break
                else:
                    if not gray:
                        gray.append(white.pop())
                continue
            nxt = graph[cur].pop()
            if (nxt in gray) | (nxt in invalid) | (nxt == cur):
                for i in gray:
                    invalid.add(i)
                if white:
                    gray = [white.pop()]
                    continue
                else:
                    break
            gray.append(nxt)
            if nxt in white:
                white.remove(nxt)
            else:
                gray.pop()
        if white:
            black = black | white
        black = list(black)
        black.sort()
        return black
```