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
        node = self.recur(root, p, q)
        return node

    def recur(self,root,p,q):
        if not root:    # 当前节点为空了 直接返回None
            return None
        if root==p or root==q:  # 当前节点为p 或 q 则找到了它们自身 返回给上一层做判断
            return root
        left =  self.recur(root.left, p, q) #递归左子树
        right = self.recur(root.right, p, q)    #递归右子树
        if left and right:  #两边都有 证明p q一定是分别在左右节点上 root一定是公共祖先
            return root
        return left if left else right  # 只有一边有 root一定不是最近公共祖先 直接把子节点传递回来                                           节点返回
```