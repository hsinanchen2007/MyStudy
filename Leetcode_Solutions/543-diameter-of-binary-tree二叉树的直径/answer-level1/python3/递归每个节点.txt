解法：对于每一个当前节点，选择左、右节点中最大的长度，然后加上1（当前路径），则是当前的最长路径深度。全局变量dis为直径，每次取左、右节点深度的和。
```
class Solution(object):
    def __init__(self):
        self.dis = 0
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        def diameter(node):
            if node is None:
                return 0
            l = diameter(node.left)
            r = diameter(node.right)
            self.dis = max(l+r, self.dis)
            # 选择左右节点中最大的长度，然后加上1（当前路径）
            return max(l,r) + 1
        diameter(root)
        return self.dis
```
