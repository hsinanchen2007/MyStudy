```python
class Solution(object):
    def levelOrder(self, root):
        res = []
        if not root:
            return res
        queue = [root]
        while queue:
            cur_level_node_num = len(queue)
            cur_level_nodes = []
            for i in range(cur_level_node_num):
                node = queue.pop(0)
                cur_level_nodes.append(node.val)
                for child in node.children:
                    queue.append(child)
            res.append(cur_level_nodes) #ok
        return res
```
