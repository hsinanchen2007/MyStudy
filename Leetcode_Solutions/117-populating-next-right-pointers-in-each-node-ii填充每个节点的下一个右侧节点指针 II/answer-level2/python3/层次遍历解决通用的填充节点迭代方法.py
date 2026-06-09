```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        root.next = None
        cur_level = [root]
        while cur_level:
            next_level = []
            for i, cur_node in enumerate(cur_level):
                cur_node.next = cur_level[i+1] if i<len(cur_level)-1 else None
                if cur_node.left:     
                    next_level.append(cur_node.left)
                if cur_node.right:
                    next_level.append(cur_node.right)
            cur_level = next_level
        return root
```
