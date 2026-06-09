### 解题思路
DFS占的内存太大了，还是用BFS吧

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        def dfs(root,L,R,summation):
            if root.val<=R and root.val>=L:
                summation.append(root.val)
            if root.left!=None:
                dfs(root.left,L,R,summation)
            if root.right!=None:
                dfs(root.right,L,R,summation)
        summation=[]
        if root==None:
            return 0
        dfs(root,L,R,summation)
        ans=sum(summation)
        return ans
```