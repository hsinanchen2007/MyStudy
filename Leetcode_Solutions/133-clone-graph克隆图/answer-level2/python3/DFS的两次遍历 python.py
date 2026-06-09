这个问题和copy list是一样的， 最简单的方法就是两遍遍历graph。
- 第一遍，只建立new node和一一mapping的关系。
- 第二遍，建立各个new node之间的关系。
        这里注意一定要遍历的是 旧的graph，而后利用一一的映射关系，来将旧的node上的关系，映射到新的node上。
        ie. mapping[old_node].next = mapping[old_node.next]
            左边的next表示关系，右边的next表示一个点，两边用mapping表示都映射到了新点上。


```
# 对set用in，理论上， 时间复杂度应该是O(1)
from collections import deque
class Solution:
    def cloneGraph(self, node: Node) -> Node:
        if not node: return None


        # 第一次遍历，只建立点，不建立关系
        queue, mapping = deque(), {node: Node(node.val)}
        queue.append(node)
        while queue:
            cur = queue.popleft()
            # 找邻居
            for neighbor in cur.neighbors:
                if neighbor not in mapping:
                    queue.append(neighbor)
                    mapping[neighbor] = Node(neighbor.val)

        # 第二次遍历，只建立关系，不建立点
        queue, marked_set = deque(), {node}
        queue.append(node)
        while queue:
            cur = queue.popleft()
            # 找邻居
            for neighbor in cur.neighbors:
                mapping[cur].neighbors.append(mapping[neighbor]) #多一步
                if neighbor not in marked_set:
                    marked_set.add(neighbor)
                    queue.append(neighbor)

        return mapping[node]
```
