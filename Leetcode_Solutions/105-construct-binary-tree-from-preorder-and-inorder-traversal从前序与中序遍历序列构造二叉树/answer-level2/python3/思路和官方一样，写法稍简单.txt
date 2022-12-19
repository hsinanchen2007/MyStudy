弱弱地问一句，为嘛同一代码每次提交运行性能结果差距悬殊？

```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if preorder:         
            idx = inorder.index(preorder[0])            
            node = TreeNode(preorder[0])
            node.left = self.buildTree(preorder[1:idx+1], inorder[:idx])
            node.right = self.buildTree(preorder[idx+1:], inorder[idx+1:])
            return node
```
