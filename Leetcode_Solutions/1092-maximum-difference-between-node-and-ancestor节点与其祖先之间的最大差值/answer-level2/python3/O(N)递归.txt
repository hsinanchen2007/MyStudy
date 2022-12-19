### 解题思路
对每个节点，只需要知道它的最大祖先和最小祖先，就可以算出当前节点最大的V
从root开始递归遍历节点，传入最大祖先的值和最小祖先的值，返回当前节点最大的V，和递归调用返回的V中，最大的值。

### 代码

```python3
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        
        def findV(node, minval, maxval):
            if not node:
                return 0

            cur = max(abs(node.val-minval), abs(node.val-maxval))
            left = findV(node.left, min(node.val, minval), max(node.val, maxval))
            right = findV(node.right, min(node.val, minval), max(node.val, maxval))
            return max(cur, left, right)
        return findV(root, root.val, root.val)
            
```