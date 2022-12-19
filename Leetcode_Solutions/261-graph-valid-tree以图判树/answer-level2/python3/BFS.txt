```
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        d = {}
        for i in range(n):
            d[i]=[]
        for i in edges:
            d[i[0]].append(i[1])
            d[i[1]].append(i[0])
        import queue
        q = queue.Queue()
        visited = set()
        q.put((0,-1))
        while not q.empty():
            s, pre = q.get()
            visited.add(s)
            for i in d[s]:
                if i==pre:
                    continue
                elif i in visited:
                    return False
                q.put((i,s))
        return len(visited)==n
```
