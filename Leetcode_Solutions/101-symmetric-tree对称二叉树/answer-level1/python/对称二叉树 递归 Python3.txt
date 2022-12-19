### 解题思路
执行用时 :48 ms, 在所有 Python3 提交中击败了33.04%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了5.43%的用户

1. 左、右的值必须相等
2. 左左、右右的值必须相等
3. 左右、右左的值必须相等
4. 左右可以同时不存在
5. 左右不能只存在一个

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        def dfs(left, right):
            if not (left or right):
                return True
            if not (left and right):
                return False
            if left.val != right.val:
                return False
            
            return dfs(left.left, right.right) and dfs(left.right, right.left)
        
        return dfs(root.left, root.right)
```