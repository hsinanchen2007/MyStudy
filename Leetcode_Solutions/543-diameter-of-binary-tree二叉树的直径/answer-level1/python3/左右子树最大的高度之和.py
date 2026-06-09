### 解题思路
此处撰写解题思路

### 代码

```python3
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def __init__(self):
        self.res = 0

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        # 以root为根节点时候 的最大值
        # 应该说每个节点都可能是根节点 这就是二叉树中递归的精妙之处把!
        if not root:
            return 0
        # 看题目 只是得出来长度 而不是具体的路径
        # 其实也可能并不穿过根节点
        left = self.depth_max(root.left)
        right = self.depth_max(root.right)
        self.res = max(self.res, left + right)
        self.diameterOfBinaryTree(root.left)
        self.diameterOfBinaryTree(root.right)
        return self.res

    def depth_max(self, node: TreeNode):
        if not node:
            return 0
        return max(self.depth_max(node.left), self.depth_max(node.right)) + 1
```