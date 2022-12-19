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

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if root == None:
            return []
        res = []
        stack = []

        def getPath(root,currentSum):
            stack.append(root.val)
            currentSum += root.val
            if (currentSum == sum) and not root.left and not root.right:
                res.append(list(stack))
            
            if root.left:
                getPath(root.left,currentSum)
            if root.right:
                getPath(root.right,currentSum)
            stack.pop(-1)



        getPath(root,0)
        return res
       
```