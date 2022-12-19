```
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        nodes=[root]
        while nodes!=[]:
            sumx=0
            for i in range(len(nodes)):
                root=nodes.pop(0)
                sumx+=root.val
                if root.left is not None:
                    nodes.append(root.left)
                if root.right is not None:
                    nodes.append(root.right)
        return sumx
```
