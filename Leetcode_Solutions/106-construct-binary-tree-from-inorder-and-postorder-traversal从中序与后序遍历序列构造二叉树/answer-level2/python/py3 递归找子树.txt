### 解题思路
其实和前序、中序的题一样，都是分治找子树

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
        if len(inorder)==0:
            return None
        #节点个数
        #找头节点
        root=TreeNode(postorder[-1])
        #找到对应头节点中序遍历的位置
        idx=inorder.index(root.val)
        #找右子树
        root.right=self.buildTree(inorder[idx+1:],postorder[idx:-1])
        #找左子树
        root.left=self.buildTree(inorder[:idx],postorder[:idx])
        return root

```