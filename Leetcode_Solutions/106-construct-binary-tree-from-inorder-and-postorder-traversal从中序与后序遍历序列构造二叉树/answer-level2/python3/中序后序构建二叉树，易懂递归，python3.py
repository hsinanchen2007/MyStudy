### 解题思路
和[https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/]()一样

如果当前输入的前序遍历为空，直接返回空

遍历中序遍历序列，寻找中序遍历中等于前序遍历第一个元素的值所在的位置，即索引i
将postorder[-1]即inorder[i]作为根节点，则：

- **根节点的左子树的后序遍历为postorder[:i]，中序遍历为inorder[:i]**

- **根节点的右子树的后序遍历为postorder[i:-1]，中序遍历为inorder[i+1:]**
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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not postorder:
            return
        for i in range(len(inorder)):
            if inorder[i] == postorder[-1]:
                root = TreeNode(postorder[-1])
                root.left = self.buildTree(inorder[:i], postorder[:i])
                root.right = self.buildTree(inorder[i+1:], postorder[i:-1])
                return root
```