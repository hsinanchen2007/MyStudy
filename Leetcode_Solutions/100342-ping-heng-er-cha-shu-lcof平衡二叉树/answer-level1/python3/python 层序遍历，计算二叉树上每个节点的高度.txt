对平衡二叉树的每个节点层序遍历，依次计算每个节点上的高度，如果某个节点的左子树与右子树的高度之差超过一，则判断为不是平衡二叉树。
```
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        #定义计算节点的高度函数
        def node_depth(root):
            return max(node_depth(root.left),node_depth(root.right)) + 1 if root else 0
        if not root:
            return True
        queue = [root]
        while queue:
            node = queue.pop(0)
            if not node:
                continue
            left_depth = node_depth(node.left) if node.left else 0
            right_depth = node_depth(node.right) if node.right else 0
            if abs(left_depth - right_depth) <= 1:
                queue.append(node.left)
                queue.append(node.right)
            else:
                return False
        return True
```
