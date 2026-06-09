### 解题思路
中序遍历得到递增数组，双指针遍历
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        res = self.helper(root)
        i = 0
        j = len(res)-1
        while i < j:
            if res[i] + res[j] == k:
                return True
            elif res[i] + res[j] > k:
                j -= 1
            else:
                i += 1
        return False

    def helper(self,root):
        if not root:
            return []
        else:
            return self.helper(root.left) + [root.val] + self.helper(root.right)
```