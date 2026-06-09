### 解题思路
看图就明白了

![image.png](https://pic.leetcode-cn.com/2de320e6bee5b676543192d9cd21c1850e5a28fcaa84f154c62d9f0b3c8bfc45-image.png)

你需要每层都判断是否是deadends中的会导致死锁的密码，而且还没被访问过，这样才能入队

### 代码

```python3
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if '0000' in deadends:return -1
        flag = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        def next_node(node:str)->List[str]:
            neighbor = []
            for i in range(len(node)):
                char = int(node[i])
                for d in [-1, 1]:
                    temp = (char + d) % 10
                    neighbor_node = node[:i] + str(temp) + node[i+1:]
                    if neighbor_node not in deadends:
                        neighbor.append(neighbor_node)
            return neighbor
        
        queue= ['0000']
        visited = {'0000'}
        time = 0
        while queue:
            n = len(queue)
            time += 1
            for _ in range(n):
                node = queue.pop(0)
                neighbor_node = next_node(node)
                for neighbor in neighbor_node:
                    if neighbor == target:
                        return time
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
        return -1


```