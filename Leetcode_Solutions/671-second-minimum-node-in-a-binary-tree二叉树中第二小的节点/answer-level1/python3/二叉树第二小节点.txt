### 解题思路
依靠多重判断

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        min_, ret = float('inf'), float('inf')
        stack = [root]
        min_ = root.val
        while stack:
            temp = stack.pop()
            if temp.left:
                if temp.left.val > min_ and (temp.left.val <= temp.right.val or temp.right.val == temp.val) and temp.left.val < ret:
                    ret = temp.left.val
                elif temp.right.val > min_ and (temp.right.val <= temp.left.val or temp.left.val == temp.val) and temp.right.val < ret:
                    ret = temp.right.val
                stack.append(temp.left)
                stack.append(temp.right)
        if ret == float('inf'):
            return -1
        else:
            return ret
```