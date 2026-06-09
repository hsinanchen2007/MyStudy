### 解题思路
首先处理特殊情况，当输入为1 []时利用if not edges: return [0]返回
只有两个以下节点时可以将两个全部返回。

接下来建立两个方向 bottom_up 和top_down的邻接表，例如adj[2] = [3,4,5]就是与节点2相接的点为3，4，5，包括了出度点和入度点。

参考了大神https://leetcode-cn.com/problems/minimum-height-trees/solution/bfs-dfs-by-powcai-3/和https://leetcode-cn.com/problems/minimum-height-trees/solution/tan-xin-fa-gen-ju-tuo-bu-pai-xu-de-si-lu-python-da/的做法，并进行了简化

### 代码

```python3
from collections import defaultdict
from collections import deque
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if not edges: return [0]
        if n <= 2: return [i for i in range(n)]
             
        adj = defaultdict(list) #邻接表
        for a,b in edges:
            adj[a].append(b)
            adj[b].append(a)
            
        leaves = [i for i in adj if len(adj[i])==1] #叶子节点
        queue = deque(leaves)
        
        while n>2:#最小高度树的根节点只会有1-2个
            size = len(queue)
            n -= size
            
            for i in range(size): #BFS
                l = queue.popleft()
                for nei in adj[l]:
                    adj[nei].remove(l) #逐层除去叶子
                    if len(adj[nei]) == 1: #出入度之和为1时说明出度或入度为1 即该节点为叶子节点
                        queue.append(nei)
        return queue
                    
        
```