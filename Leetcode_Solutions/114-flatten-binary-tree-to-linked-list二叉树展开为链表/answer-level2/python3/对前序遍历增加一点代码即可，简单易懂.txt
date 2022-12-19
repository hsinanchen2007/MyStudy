利用栈实现的前序遍历。
把当前节点的左右子树压入栈之后，修改当前的节点左右子树，左子树赋值为空，右子树赋值为当前栈顶节点。
```
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        stack = [root]
        if root == None:
            return None
        while stack:
            node = stack.pop()
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
            if stack != []:
                node.left = None
                node.right = stack[-1]
```
