### 解题思路
copy了官方题解的python版本
但思路是一样的
C++的队列存储string我不会，哭死
- 将初始状态“0000”入队
- 每次改变一位，一共产生8种状态，检测这8种状态是否处于deadends中，不处于才能加入
- 用step记录深度，如果找到target深度即为最短路径
- 如果队列为空时退出即没有找到target即为-1
- 这道题中的deadends实际帮助了剪枝
- 时BFS模板

### 代码

```python3
class Solution(object):
    def openLock(self, deadends, target):
        def neighbors(node):
            for i in range(4):
                x = int(node[i])
                for d in (-1, 1):
                    y = (x + d) % 10
                    yield node[:i] + str(y) + node[i+1:]

        dead = set(deadends)
        queue = collections.deque([('0000', 0)])
        seen = {'0000'}
        while queue:
            node, depth = queue.popleft()
            if node == target: return depth
            if node in dead: continue
            for nei in neighbors(node):
                if nei not in seen:
                    seen.add(nei)
                    queue.append((nei, depth+1))
        return -1
```