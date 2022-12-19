### 解题思路
对于二叉搜索树，左子树的节点值都小于根节点值，右子树的节点值都大于根节点值，有一个重要结论就是对二叉搜索树进行**中序遍历**可以获得升序排序的结果，这道题明显需要按照降序的顺序遍历二叉搜索树，所以我们只要按照反着中序遍历的顺序进行即可，中序遍历是左根右，那么我们就右根左进行遍历。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return None
        def get_res(root, temp):
            if root is None:
                return temp
            temp = get_res(root.right, temp)
            root.val += temp
            temp = get_res(root.left, root.val)
            return temp
        get_res(root, 0)
        return root
```