### 解题思路
获得叶子列表后比较
如何获得叶子列表？
当节点是叶子时，加入列表
当节点不是叶子时，分别查找左右子树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        leaves=[]
        def get_leaves(root):
            if not root:
                return
            if not root.left and not root.right:
                leaves.append(root.val)
            get_leaves(root.left)
            get_leaves(root.right)
        get_leaves(root1)
        a=leaves
        leaves=[]
        get_leaves(root2)
        if a==leaves:
            return True
        else:
            return False

        

```