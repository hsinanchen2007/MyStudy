### 解题思路
（本菜菜第一次写解题思路，只为记录，大家勿怪）

核心：满二叉树先根遍历结果与后根遍历结果的顺序完全相反，
关键点：将二叉树作为满二叉树来遍历，将先根遍历结果和后根遍历结果存放在列表中，即当有叶子节点为空时也要将None添加到列表中，逆置其中一个列表与另一列表比较，相等则是对称二叉树，否则不是。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        rootFir，rootAft = [], []
        def rootFirTra(tree):
            if tree == None:
                rootFir.append(None)  #注意示例2的情况，将空的子树添加到列表中有点关键
                return
            rootFir.append(tree.val)
            rootFirTra(tree.left)
            rootFirTra(tree.right)
        rootFirTra(root)

        def rootAftTra(tree):
            if tree == None:
                rootAft.append(None)
                return
            rootAftTra(tree.left)
            rootAftTra(tree.right)
            rootAft.append(tree.val)
        rootAftTra(root)

        rootAft.reverse()
        if rootFir == rootAft:
            return True
        else:
            return False
```