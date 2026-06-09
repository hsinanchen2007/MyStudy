### 解题思路
对一颗树，分别对左子树和右子树做镜像，然后交换左右子树。
然后考虑递归终止条件，当一个树是None是不存在左右子树因此返回自己。（也可以在叶子节点终止）

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return root
        mirror_left = self.mirrorTree(root.left)
        mirror_right = self.mirrorTree(root.right)
        root.left = mirror_right
        root.right = mirror_left
        return root
```