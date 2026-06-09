```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        while len(preorder)>0 or len(inorder)>0:
            root = TreeNode(preorder[0])
            root_index = inorder.index(root.val)
            root.left = self.buildTree(preorder[1:root_index+1],inorder[0:root_index])
            root.right = self.buildTree(preorder[root_index+1:],inorder[root_index+1:])
            return root
```
我个人觉得我的递归终止条件不太对，但是提交成功了，还请各位大佬看看我的代码有没有问题