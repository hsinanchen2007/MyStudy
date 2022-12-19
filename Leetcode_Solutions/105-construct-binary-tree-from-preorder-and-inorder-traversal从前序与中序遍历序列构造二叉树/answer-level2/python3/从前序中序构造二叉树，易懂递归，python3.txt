### 解题思路
如果当前输入的前序遍历为空，直接返回空

遍历中序遍历序列，寻找中序遍历中等于前序遍历第一个元素的值所在的位置，即索引i
**将preorder[0]即inorder[i]作为根节点**，则：

**- 根节点的左子树的前序遍历为preorder[1:i+1]，中序遍历为inorder[:i]
- 根节点的右子树的前序遍历为preorder[i+1:]，中序遍历为inorder[i+1:]**

左子树和右子树均可以递归生成

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
        if not preorder:
            return
        for i in range(len(inorder)):
            if inorder[i] == preorder[0]:
                root = TreeNode(preorder[0])
                root.left = self.buildTree(preorder[1:i+1], inorder[:i])
                root.right = self.buildTree(preorder[i+1:], inorder[i+1:])
                return root
```