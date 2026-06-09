### 解题思路
先递归创建所有节点，再递归绑定邻居关系。

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""

class Solution:
    def cloneGraph(self, nd: 'Node') -> 'Node':
        if not nd:
            return None
        record = list()
        nodes = dict()
        def catch(node):
            cur_node = None
            if node.val not in record:
                record.append(node.val)
                # ns = list()
                # if n.neighbors:
                if node.val not in nodes.keys():
                    tmp = Node(node.val)
                    if not cur_node:
                        cur_node = tmp
                    nodes[node.val] = tmp
                for n in node.neighbors:
                    catch(n)
            else:
                return
            return cur_node

        def copy_neighbors(node):
            if node.val in record:
                record.remove(node.val)
                ns = list()
                # if n.neighbors:
                for n in node.neighbors:
                    ns.append(copy_neighbors(n))
                nodes[node.val].neighbors = ns
                return nodes[node.val]
            else:
                return nodes[node.val]
        cur_node = catch(nd)
        # print(nodes)
        copy_neighbors(nd)
        return cur_node

```