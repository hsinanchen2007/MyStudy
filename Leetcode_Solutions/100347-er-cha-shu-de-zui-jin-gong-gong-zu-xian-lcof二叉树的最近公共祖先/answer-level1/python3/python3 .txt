### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        #如果当前为空返回空节点
        if not root:
            return None
        #如果当前节点为P，q 返回当前节点
        if root in [p,q]:
            return root
        #分别递归查找左右子树
        left=self.lowestCommonAncestor(root.left,p,q)
        right=self.lowestCommonAncestor(root.right,p,q)
        # 如果左右子树各有一个p,q,返回当前节点
        if left and right:
            return root
        
        #都在左边：
        elif left:
            return left
        
        #都在右边
        elif right:
            return right
        return None
```