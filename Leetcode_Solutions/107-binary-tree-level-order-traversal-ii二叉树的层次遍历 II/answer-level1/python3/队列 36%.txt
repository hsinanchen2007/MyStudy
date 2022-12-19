```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        stack=[root]
        ans=[]
        while stack:
            n = len(stack)
            level=[]
            for _ in range(n):
                node=stack.pop()
                level.append(node.val)
                if node.left != None:
                    stack.insert(0,node.left)
                if node.right != None:
                    stack.insert(0,node.right)
            ans.insert(0,level)
        return ans

```
