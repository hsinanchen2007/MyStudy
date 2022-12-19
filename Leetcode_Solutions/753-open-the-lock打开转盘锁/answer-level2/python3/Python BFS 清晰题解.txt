```python
from queue import Queue

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends) # in 操作在set中时间复杂度为O(1)
        if '0000' in deadends:
            return -1
        
        # -------------------------------BFS 开始----------------------------------
        # 初始化根节点
        q = Queue()
        q.put(('0000', 0)) # (当前节点值，转动步数)
        
        # 开始循环队列
        while not q.empty():
            
            # 取出一个节点
            node, step = q.get()
            
            # 放入周围节点
            for i in range(4):
                for add in (1, -1):
                    cur = node[:i] + str((int(node[i]) + add) % 10) + node[i+1:]
                    if cur == target:
                        return step + 1
                    if not cur in deadends:
                        q.put((cur, step + 1))
                        deadends.add(cur) # 避免重复搜索
        # -------------------------------------------------------------------------
        return -1
```
为什么这题要用 BFS(广度优先搜索) ？根据题意，我们需要找到最少的解锁步数，这实际上可以认为是在图上搜索最短路径。BFS 总是优先搜索距离根节点近的节点，因此它搜索到的路径就是最短路径
- 以当前锁上的数字为根，所有能达到的数字为一阶邻域（子节点）进行搜索
