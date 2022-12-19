```python []
class Solution:
    
    def storeNodes(self, root, nodes):
        if not root: return 
        self.storeNodes(root.left, nodes)
        nodes.append(root)
        self.storeNodes(root.right, nodes)
    def buildTree(self, nodes, start, end):
        if start > end:
            return None
        mid = (start + end) // 2
        root = nodes[mid]
        root.left = self.buildTree(nodes, start, mid - 1)
        root.right = self.buildTree(nodes, mid + 1, end)
        return root
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nodes = []
        self.storeNodes(root, nodes)
        # print(nodes)
        n = len(nodes)
        return self.buildTree(nodes, 0, n-1)
```