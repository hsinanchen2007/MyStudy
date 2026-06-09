### 解题思路
参考官方题解递归思路

### 代码

```python3
class Solution(object):
    def isSymmetric(self, root):
        if not root:
            return True
        def dfs(left,right):
            if (left == None and right == None):
                return True
            if (left == None or right == None):
                return False
            if left.val!=right.val:
                return False
            return dfs(left.left,right.right) and dfs(left.right,right.left)
        return dfs(root.left,root.right)
```