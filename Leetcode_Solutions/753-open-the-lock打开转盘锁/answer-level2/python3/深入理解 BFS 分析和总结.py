**思路：用BFS解决这道题目，关键在于将题目转变成BFS的解题模式**

BFS一般步骤：先确定一个搜索范围、起始点、标记和目标，然后写出相邻关系函数。先将起始点出列，马上与它相邻点入列，并标记为已访问，如此循环，直到列表为空。这样就能一直搜索，直到找到目标点。

题目特征：
1. 搜索范围：0000至9999这一千个节点
2. 起始节点：0000
3. 相邻关系：4个位置每次只有一个能+1或者-1（0-1则为9）
4. 目标节点：target
5. 额外条件：节点不会在deadends中

这样就可以很快得出相应的程序：
```
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def neighbors(node):
            for i in range(0, 4):
                x = int(node[i])
                for d in(-1, 1):
                    y = (x + d) % 10
                    yield node[:i] + str(y) + node[i+1:]
        
        queue = collections.deque([('0000', 0)])
        dead = set(deadends)
        seen = {'0000'}
        while queue:
            node, depth = queue.popleft()
            if node == target:
                return depth
            if node in dead:
                continue
            else:
                for nei in neighbors(node):
                    if nei not in seen:
                        seen.add(nei)
                        queue.append((nei, depth+1))
        return -1
```
