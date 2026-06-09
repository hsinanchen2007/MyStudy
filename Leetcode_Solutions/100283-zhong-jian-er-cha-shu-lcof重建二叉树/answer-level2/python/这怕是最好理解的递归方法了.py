### 解题思路
        1.前序遍历的第 1 个结点一定是二叉树的根结点；
        2.在中序遍历中，根结点把中序遍历序列分成了两个部分，左边部分构成了二叉树的根结点的左子树，
          右边部分构成了二叉树的根结点的右子树，返回当前的跟节点；
        3.分别对左右子树进行步骤1和2的操作。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        """
        1.前序遍历的第 1 个结点一定是二叉树的根结点；
        2.在中序遍历中，根结点把中序遍历序列分成了两个部分，左边部分构成了二叉树的根结点的左子树，
          右边部分构成了二叉树的根结点的右子树，返回当前的跟节点；
        3.分别对左右子树进行步骤1和2的操作。
        """
        if not preorder or not inorder or len(preorder) != len(inorder):
            return None
        # 找到当前树的根节点
        root = TreeNode(preorder[0])
        # 找到当前树根节点在中序遍历中的索引
        index = inorder.index(preorder[0])
        # 在前序遍历数组中划分左子树和右子树
        pre_left = preorder[1:index + 1]
        pre_right = preorder[index + 1:]
        # 在中序遍历数组中划分左子树和右子树
        in_left = inorder[0: index]
        in_right = inorder[index + 1:]
        # 递归遍历划分的左右子树
        root.left = self.buildTree(pre_left, in_left)
        root.right = self.buildTree(pre_right, in_right)
        # 返回当前的节点，已经找到的结果
        return root
```