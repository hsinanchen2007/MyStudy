### 解题思路
**（1）文字思路**

在N*N地图中，海洋距离相邻陆地的最远距离是多少
此时需要注意的是，不是求图中海洋到陆地的最远距离，而是有条件的求到相邻陆地的最远距离
如果陆地为行动者，形成初始层级队列，每个陆地都可走一步；
所到之地加入队列形成第二层级；
再次遍历，形成第三层级；
以此类推，直到队列中不再存在行动者。

思维图可参考：
其中初始队列为所有陆地组成的第一层级
![image.png](https://pic.leetcode-cn.com/d5865ed749a2543190603ec4cd725e1e9c9ca85e1f0fcbb9d70896c68a2262fb-image.png)

可以利用BFS（广度优先搜索）算法
关于BFS运行思路可参考视频：
https://search.bilibili.com/all?keyword=Python%20BFS

**（2）代码思路**

**第一步**：all lands组成的初始队列queue
![image.png](https://pic.leetcode-cn.com/3f9fdb6a8f8d1c2fb4ba81fe878f4d5e06b54e01bc8a6967d579014e1e0baaa8-image.png)
**第二步**，判断地图中是否均为海洋或陆地，如果是，返回值-1
![image.png](https://pic.leetcode-cn.com/9d2e1f30b7ccc6588f09647522f91f84316d7272577fdde780bac3b23167b477-image.png)
**第三步**，循环队列中queue点的上下左右点是否为海洋，如果是，去除海洋值标志，并添加在中间队列tmp中；初始层级遍历结束后（此时queue已为空），queue赋值为中间队列temp
![image.png](https://pic.leetcode-cn.com/ef6c6d55c404c13e462c60a1c42e31fc7d882da083f96c7a2fb6e61df52188ed-image.png)
**第四步**，循环导致距离多加1，因此返回值需减1


### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        queue = [(i,j) for i in range(n) for j in range(n) if grid[i][j] == 1]
        if len(queue) == 0 or len(queue) == n**2:
            return -1
        dist = 0
        temp = []
        while len(queue):
            for i in range(len(queue)):
                x,y = queue.pop(0)
                for xi, yj in [(x-1,y),(x+1,y),(x,y-1),(x,y+1)]:
                    if xi >= 0 and xi < n and yj >= 0 and yj < n and grid[xi][yj] == 0:
                        temp.append((xi,yj))
                        grid[xi][yj] = -1
            dist +=1
            queue = temp
        return dist-1


```