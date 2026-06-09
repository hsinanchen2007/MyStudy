### 解题思路

**中序序列** 外加先序或者后序，都可以还原原始的二叉树，但是只有先序和后序不能保证还原二叉树。

思路是先序序列第一个元素一定是根（后序则是最后一个元素是根）。

然后找根在中序中的位置，把中序切成两个数组。左边是左子树，右边是右子树。然后根据左子树和右子树元素数量把先序序列也切分成两个，递归构造子树就可以了。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder: return None             # 空列表返回空树
        r = TreeNode(preorder[0])                # 先序第一个元素一定是根
        rid = inorder.index(preorder[0])         # 中序找出根，那么中序根左边是左子树，右边是右子树
        r.left = self.buildTree(preorder[1:1+rid], inorder[:rid])     # 递归构造左子树
        r.right = self.buildTree(preorder[rid+1:], inorder[rid+1:])   # 递归构造右子树
        return r

```