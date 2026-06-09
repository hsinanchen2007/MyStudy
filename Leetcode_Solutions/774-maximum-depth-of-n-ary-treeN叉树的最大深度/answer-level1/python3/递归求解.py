```python3 []
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0
        
        # 没有子树，只有根节点1层
        if root.children is None or len(root.children) == 0:
            return 1
        
        # 存在多个子树，则对每个子树递归求最大深度
        return 1 + max(map(self.maxDepth, root.children))
```

