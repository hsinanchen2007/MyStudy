### 解题思路
中序遍历得到递增数组再处理

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        res = self.helper(root)
        m = res[1]-res[0]
        for i in range(len(res)-1):
            if res[i+1] - res[i] < m:
                m = res[i+1] - res[i]
        return m

    
    def helper(self,root):
        if not root:
            return []
        else:
            return self.helper(root.left) + [root.val] + self.helper(root.right)
```