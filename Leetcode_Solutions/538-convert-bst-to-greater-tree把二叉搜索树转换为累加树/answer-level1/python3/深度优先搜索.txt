先遍历右子树，储存根节点，再遍历左子树：

```python []
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        self.num = 0
        def depthfirstsearch(root):
            if root is None:
                return 
            else:
                depthfirstsearch(root.right)
                self.num = self.num + root.val
                root.val = self.num
                depthfirstsearch(root.left)
                return root
        return depthfirstsearch(root)


```

