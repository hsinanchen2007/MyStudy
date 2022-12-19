迭代法：root非空，先保存数值，然后右孩子先压栈，左孩子后压栈，依次遍历

```
def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # 方法一：递归
        res = []
        def pre_travel(node):
            if node is None:
                return 
            res.append(node.val)
            pre_travel(node.left)
            pre_travel(node.right)
        pre_travel(root)
        return res
        # 方法二：迭代
        stack, res = [root], []
        if root is None:
            return []
        while stack:
            node = stack.pop()
            if node is not None:
                res.append(node.val)
                if node.right is not None:
                    stack.append(node.right)
                if node.left is not None:
                    stack.append(node.left)
        return res
```
