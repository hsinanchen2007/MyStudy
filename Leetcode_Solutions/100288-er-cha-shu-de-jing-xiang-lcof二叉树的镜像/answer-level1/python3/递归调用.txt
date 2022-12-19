```
class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root!=None:
            root.left, root.right = root.right, root.left
            self.mirrorTree(root.left)
            self.mirrorTree(root.right)
        return root
```
当root非空，将root的两个孩子对换，对两个孩子重复此操作，直到所有节点完成镜像操作。
返回root
