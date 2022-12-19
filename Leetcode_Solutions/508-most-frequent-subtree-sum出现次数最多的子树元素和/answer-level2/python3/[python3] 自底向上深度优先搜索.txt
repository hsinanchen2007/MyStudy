```python
class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        def DFS(root: TreeNode) -> int:
            if not root:
                return 0
            if not (root.left or root.right):
                self.node.append(root.val)
                return root.val
            l, r = DFS(root.left), DFS(root.right)
            c = l + r + root.val
            self.node.append(c)
            return c
        if not root:
            return []
        self.node = []
        DFS(root)
        c = collections.Counter(self.node)
        max_subtree = max(c.values())
        return list(filter(lambda x: c[x] == max_subtree, c))
        
```
