### 解题思路

 
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        ans = []
        if not root:
            return ans
        else:
            ans = []
            cur = [root]
            while cur:
                subans = []
                nextstack = []
                for node in cur:
                    if node.left:
                        nextstack.append(node.left)
                    if node.right:
                        nextstack.append(node.right)
                    subans.append(node.val)
                cur = nextstack
                ans.append(subans)
            return ans

            


        
```