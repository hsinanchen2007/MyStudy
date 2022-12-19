**题解思路**
**·** 因为是中序遍历，遇到节点时应先访问节点的左分支，所以应沿着树的左枝下行将遇到的左分支依次压入栈；
**·** 遇到空树时说明遍历到叶子节点了，这时需要回溯，将栈中保存的左分支取出，去遍历它

**代码**
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        res = []
        node = root
        while stack or node:
            while node: 
                stack.append(node)
                node = node.left
            node = stack.pop()
            res.append(node.val)
            node = node.right
        return res
```


