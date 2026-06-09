### 解题思路
对二叉树进行两种不同的中序遍历：
1. 第一种中序遍历中将左孩子放在父节点的左边，右孩子放在父节点的右边
2. 第二种中序遍历中将右孩子放在父节点的左边，左孩子放在父节点的右边
对比两种遍历的结果，如果结果相同，则返回True，否则返回False

**注意：不同的树形结构有可能产生相同的遍历结果，所有在遍历时加上节点的层级信息**

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
        l1 = []
        l2 = []
        def head(root, layer):
            if not root:
                return
            else:
                if root.left: head(root.left, layer+1)
                l1.append([root.val, layer])
                if root.right: head(root.right, layer+1)
        
        def tail(root, layer):
            if not root:
                return
            else:
                if root.right: tail(root.right, layer+1)
                l2.append([root.val, layer])
                if root.left: tail(root.left, layer+1)

        head(root, 1)
        tail(root, 1)

        if len(l1) != len(l2): return False
        for i, j in zip(l1, l2):
            if i == j: continue
            else: return False
        return True

```