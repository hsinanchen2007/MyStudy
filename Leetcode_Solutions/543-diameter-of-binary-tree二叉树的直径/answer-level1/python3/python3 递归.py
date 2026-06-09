### 解题思路
与官方题解类似。在递归求解各个节点高度的过程中，顺便使用self.res记录当前节点的直径长度（即经过该节点的路径长度的最大值，等于左子树高度+右子树高度）。
不断比较每个节点的直径长度，并更新self.res，最终所有节点遍历完成后self.res将储存整个树的直径长度。

时间复杂度和空间复杂度：O(n)
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.res=0
        self.get_height(root)
        return self.res

    def get_height(self, root):
        if not root:
            return 0
        l=self.get_height(root.left)
        r=self.get_height(root.right)
        self.res=max(self.res,l+r)
        return max(l,r)+1

```