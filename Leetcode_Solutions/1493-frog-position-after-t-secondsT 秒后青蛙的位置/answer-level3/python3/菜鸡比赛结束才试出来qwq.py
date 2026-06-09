### 解题思路

考虑的情况太少，菜鸡比赛结束才试出来qwq

bfs维护三个变量，当前节点，当前节点的同级节点的数量，已经经过的时间。

注意：无向树的话，当前节点可能出现的地方不仅在edge[0]，而且有可能在edge[1]

```
if node == target and ((can_travel == False) or (can_travel == True and left_t == 0)):
```
这句感觉挺关键的，如果遍历到目标节点的时候，需要考虑两种情况：
1. 剩下的时间没有了，此时可以输出
2. 剩下的时间还有，但是这个时候没有任何可以遍历的节点了。

最后用遍历概率就是brother_list当中的各项的乘积的倒数。

### 代码

```python3
import queue
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        q = queue.deque()
        if target == 1 and t == 0:
            return 1
        visited_set = set()
        visited_node = set()
        q.appendleft((1,[1],t))
        while len(q) > 0:
            node, brother_list, left_t = q.pop()
            print(node, brother_list, left_t)
            if node in visited_node:
                continue
            visited_node.add(node)
            brother = 0
            if left_t < 0:
                continue
            for edge in edges:
                if tuple(edge) in visited_set:
                    continue
                
                if node == edge[0]:
                    brother+=1
                    visited_set.add(tuple(edge))
                elif node == edge[1]:
                    brother+=1
                    visited_set.add(tuple(edge))
            # brother_list.append(brother)
            can_travel = False
            for edge in visited_set:
                if node == edge[0]:
                    if edge[1] not in visited_node:
                        q.appendleft((edge[1], brother_list + [brother], left_t - 1))
                        can_travel = True
                elif node == edge[1]:
                    if edge[0] not in visited_node:
                        q.appendleft((edge[0], brother_list + [brother], left_t - 1))
                        can_travel = True
            if node == target and ((can_travel == False) or (can_travel == True and left_t == 0)):
                res = 1
                for item in brother_list:
                    res /= item
                return res
            
        return 0
```