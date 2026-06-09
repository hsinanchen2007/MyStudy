
```python []
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        
        if root is None:
            return []
        
        if root.left is None and root.right is None:
            return [str(root.val)]
        
        paths = []
        for path in self.binaryTreePaths(root.left):
            paths.append(str(root.val) + '->' + path)
            
        for path in self.binaryTreePaths(root.right):
            paths.append(str(root.val) + '->' + path)
            
        return paths