```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        stack = [root]
        ans=[]
        tmp=[]
        while stack:
            tmp=[]
            size =len(stack)
            for _ in range(size):
                node = stack.pop()
                tmp.append(node.val)
                if node.right !=None:
                    stack.insert(0,node.right)
                if node.left !=None:
                    stack.insert(0,node.left)
            ans.append(tmp[0])
        return ans
```
