### 解题思路

递归求解每个节点的最长路径

### 代码

```python3

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        self.rev = 0
        def test(node):
            if not node:
                return 0
            left = test(node.left)
            right = test(node.right)
            if left + right + 1 > self.rev:
                self.rev = left + right + 1 
            
            return max(left, right) + 1
        
        test(root)
        return self.rev - 1
```