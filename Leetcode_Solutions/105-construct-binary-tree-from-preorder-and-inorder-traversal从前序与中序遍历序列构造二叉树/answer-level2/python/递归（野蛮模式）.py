### 解题思路

    找到中序遍历的点，再构造根结点、构造左子树、构造右子树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildHelp(self, pre, mid):
        for i in range( len(mid) ):
            if pre[0]==mid[i]:
                # 找到中序遍历的根，构造根、左子树、右子树
                root = TreeNode(pre[0])
                root.left =  self.buildHelp(pre[1:i+1], mid[0:i])
                root.right = self.buildTree(pre[i+1:], mid[i+1:])
                return root
                
        return None

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.buildHelp(preorder, inorder)
```