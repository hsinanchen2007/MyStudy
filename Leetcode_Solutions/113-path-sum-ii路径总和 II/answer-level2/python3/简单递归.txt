
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root:
            return []
        res = []
        def helper(root,sum,tmp):
            if not root:
                return
            if not root.left and not root.right:
                if sum-root.val == 0:
                    res.append(tmp+[root.val])
                else:
                    return
            helper(root.left,sum-root.val,tmp+[root.val])
            helper(root.right,sum-root.val,tmp+[root.val])
            return
        helper(root,sum,[])
        return res
                
            
```