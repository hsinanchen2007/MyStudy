### 解题思路
一个最长的路径肯定是过某个节点，那么这个节点的左子树深度加上右子树深度再加一(他自己)就是过他的路径的最长的长度，那么只要找到所有节点的左子树深度+右子树深度，就能找到最长路径了
所以其实这个题求的是子树深度。
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.radius = 0
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root == None:
            return 0
        self.treeDepth(root)
        return self.radius

    def treeDepth(self,root):
        if root.left == None:
            leftDepth = 0
        else:
            leftDepth = self.treeDepth(root.left)

        if root.right == None:
            rightDepth = 0
        else:
            rightDepth = self.treeDepth(root.right)
        if leftDepth + rightDepth > self.radius:
            self.radius = leftDepth + rightDepth
        return max(leftDepth , rightDepth) + 1
```