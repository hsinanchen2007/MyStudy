使用堆实现，非递归，只有当左子树无子节点的时候才加上左子树的值
```
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        res = 0
        if root == None:
            return res
        nodes = [root]
        while nodes:
            node = nodes.pop()
            if node.left:
                nodes.append(node.left)
            if node.right:
                nodes.append(node.right)
            if node.left and node.left.left == None and node.left.right == None:
                res += node.left.val
        return res
```
