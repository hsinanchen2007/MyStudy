由于是算步数，则优先想到 BFS 来暴搜。将图的关系反向映射回来找到可出度，但是会直接TLE。于是我加了个减枝，将已经遍历过的节点不仅染色，而且在反向映射也直接干掉，这样就避免了重复。

另外这个解法也要 2s 多，不知道这题的限制时间是多少。听朋友说可以做双向广搜，有时间试试。

| 提交结果 | 执行用时 | 内存消耗 | 语言 |
| --- | --- | --- | --- |
| 通过 | 2332 ms | 56.1 MB | Python3 |



```python
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
        if S == T: return 0
        g = collections.defaultdict(set)
        for i, r in enumerate(routes):
            for s in r:
                g[s].add(i)
        # print(g)
        
        import queue
        que = queue.Queue()
        que.put((S, 1))
        vis = [False for _ in range(1000005)]
        
        while not que.empty():
            cur_s, res = que.get()
            vis[cur_s] = True
            for i in g[cur_s]: 
                for nxt_s in routes[i]:
                    if vis[nxt_s]: continue    
                    if nxt_s == T: return res   
                    # 这里做一个节点剪枝
                    if nxt_s in g and i in g[nxt_s]:
                        g[nxt_s].remove(i)
                    que.put((nxt_s, res + 1))
                
        return -1
```
