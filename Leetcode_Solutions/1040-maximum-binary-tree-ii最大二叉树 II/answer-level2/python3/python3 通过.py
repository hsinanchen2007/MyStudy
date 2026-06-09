最后还要多return一下 不然一直是空的
```
class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        add = TreeNode(val)
        if val > root.val:
            add.left = root
            return add
        def leaf(root, val):
            if root.right == None:
                root.right = add
            if root.right.val > val:
                leaf(root.right, val)
            if root.right.val < val:
                add.left = root.right
                root.right = add
            return root
        return leaf(root, val)
        
```
