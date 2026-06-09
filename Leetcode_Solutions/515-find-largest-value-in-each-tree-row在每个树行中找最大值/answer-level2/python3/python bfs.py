```
from collections import OrderedDict
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        max_dict = OrderedDict()
        if not root:
            return []
        def bfs(node, level=0):
            max_val = max_dict.setdefault(level, float('-inf'))
            max_dict[level] = max(max_val, node.val)
            childrens = [node.left, node.right]
            for c in childrens:
                if c:
                    bfs(c, level + 1)
        bfs(root)
        return max_dict.values()
```
