### 解题思路
如果root为None，返回True
为root建立一个合理的取值开区间(lower, upper）
如果root.val不在合理区间内，返回False
如果root.left不在合理区间内返回False
如果root.right不在合理开区间内返回False
如果root，和左孩子右孩子都在合理区间内，返回True

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
        return method(root)
        
def method(root, lower=float("-inf"), upper=float("inf")):
    if not root:
        return True
    val = root.val
    if val <= lower or val >= upper:
        return False
    if not method(root.left, lower, val):
        return False
    if not method(root.right, val, upper):
        return False
    return True
        
           
```