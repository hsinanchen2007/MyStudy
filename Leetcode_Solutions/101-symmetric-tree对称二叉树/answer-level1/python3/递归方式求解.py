### 解题思路
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.symmetric(root, root)
    
    def symmetric(self, node1: TreeNode, node2: TreeNode) -> bool:
        if not node1 and not node2:
            return True
        if not node1 and not node2:
            return True
        if not node1:
            return False
        if not node2:
            return False
        return node1.val == node2.val and self.symmetric(node1.left, node2.right) and \
         self.symmetric(node1.right, node2.left)
        
```