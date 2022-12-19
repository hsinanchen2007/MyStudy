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
    def isValidBST(self, root: TreeNode) -> bool:
        # 判断是否为 []
        if root:
            if root.left:
                # 返回的是左子树的所有叶子节点组成列表
                l = self.isValidBST(root.left)
                # 如果左子树不符合要求或者当前节点小于左子树中的最大的节点则不成立
                if not l or root.val <= max(l):
                    return False
            else:
                l = []
            if root.right:
                # 返回的是右子树的所有叶子节点组成列表
                r = self.isValidBST(root.right)
                # 如果右子树不符合要求或者当前节点大于右子树中的最小的节点则不成立
                if not r or root.val >= min(r):
                    return False
            else:
                r = []
            return l+r+[root.val]
        # 如果没错或者[]都返回True
        return True
            
           
```