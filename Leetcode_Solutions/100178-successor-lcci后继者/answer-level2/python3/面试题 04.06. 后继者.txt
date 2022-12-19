### 解题思路

中序遍历，标记修改。

### 代码

```python []
class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        flag, ans = False, None
        def f(r):
            nonlocal flag, ans
            if r and not ans:
                f(r.left)
                if flag:
                    ans = r
                    flag = False
                if r is p:
                    flag = True
                f(r.right)
        f(root)
        return ans
```