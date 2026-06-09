### 解题思路
递归
### 代码

```python3
class Solution:
    def __init__(self):
        self.ans = []


    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return
        self.ans.append(root.val)
        self.preorderTraversal(root.left)
        self.preorderTraversal(root.right)
        return self.ans
```

### 解题思路
迭代

### 代码

```python3
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        stack, output = [root], []
        while stack:
            root = stack.pop()
            if root is not None:
                output.append(root.val)
                if root.right is not None:
                    stack.append(root.right)
                if root.left is not None:
                    stack.append(root.left)
        return output
```