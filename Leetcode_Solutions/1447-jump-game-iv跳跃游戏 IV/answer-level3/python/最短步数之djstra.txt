### 解题思路

求最短步数，那就构造图，用djstra方法求最少的步数。

这题之所以为难题，就是因为图中可能存在大量循环边（相同数字构成）。对于这些边，仅遍历一次。
`
if arr[idx] not in nums_visited:
    next_nodes |= idx_map[arr[idx]]
`
![image.png](https://pic.leetcode-cn.com/13130f9ff01fac5b5c3cecd66f72fa793ea0b02e871b22a448eef50bdbc00162-image.png)


### 代码

```python
class Solution(object):
    def minJumps(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        graph = [set() for _ in xrange(n)]
        idx_map = collections.defaultdict(set)
        for i, a in enumerate(arr):
            idx_map[a].add(i)

        pq = [(0, 0)]
        dist = [float("inf")] * n
        dist[0] = 0
        nums_visited = set()
        while pq:
            steps, idx = heapq.heappop(pq)
            idx = -idx
            if idx == n - 1: return steps
            if steps > dist[idx]: continue
            next_nodes = set()
            if idx > 0:
                next_nodes.add(idx - 1)
            if idx < n - 1:
                next_nodes.add(idx + 1)
            if arr[idx] not in nums_visited:
                next_nodes |= idx_map[arr[idx]]
            for next_node in next_nodes:
                if dist[next_node] > steps + 1:
                    dist[next_node] = steps + 1
                    heapq.heappush(pq, (steps + 1, -next_node))
            nums_visited.add(arr[idx])
        return -1
```