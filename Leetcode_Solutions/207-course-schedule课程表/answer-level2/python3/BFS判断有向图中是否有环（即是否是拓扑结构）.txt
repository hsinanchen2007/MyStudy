### 解题思路
对于有向图如何表示呢？我们用入度表和邻居矩阵表示，如下图

![image.png](https://pic.leetcode-cn.com/a7efa8632ff795b1b661a5eb47616013f52ac628220536f3b750f3dc6adc22ea-image.png)

![image.png](https://pic.leetcode-cn.com/50a1767b2395684503bd37d2581ffb1a27fe3d50de8bce578db43b3a3ec2d4d1-image.png)

那么由于节点是从0-n-1连续数字，我们可以借助下标表示节点编号。
图例为`[[[1,0],[3,0],[3,1],[2,1],[4,2],[4,3],[1,4]]]`那么：
入度表：`[0, 2, 1, 2, 2]` 
邻接矩阵：`[[1, 3], [3, 2], [4], [4], [1]]`
然后我们用BFS进行判断图中是否有环：(BFS是通过对列来实现的)
1. 首先我们将所有**入度为0**的节点入队
2. 接着将队列头中节点出队， 并将`课程数减一`
3. 在邻接矩阵中寻找出队节点的邻居，将`邻居节点的入度减一`，如果减一后邻居的入度为0，那么将该邻居入队。
4. 如果图中有环，那么一定会碰到所有邻居入度不为0，最后导致对列pop掉上一层所有节点后，退出循环
5. 所以如果课程数最后为0，那么图中没有换，否则有环


### 代码

```python3
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegrees = [0 for _ in range(numCourses)]
        adjacency = [[] for _ in range(numCourses)]
        
        for cur, pre in prerequisites:
            indegrees[cur] += 1
            adjacency[pre].append(cur)
        print(indegrees, adjacency)

        queue = [] # 首先扎到所有入度为0的节点入队   
        for i in range(len(indegrees)):
            if indegrees[i] == 0:
                queue.append(i)
        
        while queue:
            pre = queue.pop(0)
            numCourses -= 1
            for neighbor in adjacency[pre]:
                indegrees[neighbor] -= 1
                if indegrees[neighbor] == 0:
                    queue.append(neighbor)
                    
        if numCourses == 0:
            return True
        else:
            return False
        
```