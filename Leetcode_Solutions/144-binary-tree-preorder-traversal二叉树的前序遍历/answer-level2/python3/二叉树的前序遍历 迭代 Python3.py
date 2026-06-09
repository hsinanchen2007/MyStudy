### 解题思路
执行用时 :40 ms, 在所有 Python3 提交中击败了41.12%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了5.03%的用户

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stk = []
        
        while root or stk:
            if root:
                res.append(root.val)
                stk.append(root)
                root = root.left
            else:
                top = stk.pop()
                root = top.right
                
        return res
            
```