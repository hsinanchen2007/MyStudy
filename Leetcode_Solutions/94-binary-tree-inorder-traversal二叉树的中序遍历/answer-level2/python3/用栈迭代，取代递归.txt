![image.png](https://pic.leetcode-cn.com/52dc5c6aea6128cfe2c5a7e0792ddb91276a5e17f7c26283fb8ce58c0d79c72e-image.png)

```python []
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack: List[TreeNode] = []
        result: List[int] = []
        while root or stack:
            if root:
                stack.append(root)
                if root.left:
                    root = root.left
                else:
                    root = None
            else:  # stack
                root = stack.pop()
                result.append(root.val)
                root = root.right
        return result 
```
