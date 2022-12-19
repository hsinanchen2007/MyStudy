### 解题思路
知道要用递归算法，但是每次都理不清楚递归条件。。。。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

        # leftDep = 0
        # rightDep = 0
        # maxDep = 0
        # def helper(rootNode):
        #     if rootNode == None:
        #         return 0
            
        #     if rootNode.left != None:
        #         leftDep += 1
        #         leftDep = self.helper(rootNode.left)
            
        #     if root.right != None:
        #         rightDep += 1
        #         rightDep = self.helper(root.right)
        #     maxDep = max(leftDep, rightDep, maxDep)
        #     return maxDep
        
        # dep = helper(root)
        # return dep 

        

        
```