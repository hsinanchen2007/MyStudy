### 解题思路
        思路：广度优先方法，把该题抽象为一个图，我们其实是要寻找一个到达n的最短完全平方数路径；
        因此我们需要构建一个到达n的完全平方数的图，然后采用BFS的方法搜索最短路径。 
        如何构建图：
        1. 从n到0，每个数都是一个节点；
        2. 如果从x到y相差一个完全平方数，则x和y之间连接一条边；
        3. 最后得到一个0到n的无权图，我们直接求n到0的最短路径；

这里根据题画了一个图（手绘，将就看），方便理解，当输入n=12时，可以看到最短的路径长度是3，就是我们要的答案
![IMG_713261D3FAFF-1.jpeg](https://pic.leetcode-cn.com/1adf50d29d8a45a43e5747fd9d57fcea7617c50d66a8730eb6dd5fb53921ec85-IMG_713261D3FAFF-1.jpeg)


### 代码

```python3

class Solution:
    def numSquares(self, n: int) -> int:
        """
        思路：广度优先方法，把该题抽象为一个图，我们其实是要寻找一个到达n的最短完全平方数路径；
        因此我们需要构建一个到达n的完全平方数的图，然后采用BFS的方法搜索最短路径。 
        如何构建图：
        1. 从n到0，每个数都是一个节点；
        2. 如果从x到y相差一个完全平方数，则x和y之间连接一条边；
        3. 最后得到一个0到n的无权图，我们直接求n到0的最短路径；
        """
        visited, queue = set(), collections.deque([(n, 0)])
        while queue:
            num, step = queue.popleft()
            # 构建一个从n到0的完全平方数的图
            graph = [num-i*i for i in range(1, int(num ** 0.5) + 1)]
            # print(num, graph, visited, queue)
            for node in graph:
                if node == 0: # 如果node=0,那么可以直接走到终点，那么返回已经走的步数
                    return step + 1
                if node not in visited: # 避免去走已经走过的节点, 如果不这么做，内存会爆
                    visited.add(node)
                    queue.append((node, step+1))
```