### 解题思路
我们使用辅助函数 $checkHeight$ 从根节点开始递归向下检查每一棵子树的高度。如果子树的平衡的，返回子树的实际高度；反之返回一个错误代码，这个错误代码可用 `float('inf')` 表示。

### 代码

```python []
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def checkHeight(root):
            if not root: return -1

            leftHeight = checkHeight(root.left)
            if leftHeight == float('inf'): return float('inf') # 向上传递错误

            rightHeight = checkHeight(root.right)
            if rightHeight == float('inf'): return float('inf') # 向上传递错误

            heightDiff = leftHeight - rightHeight
            if abs(heightDiff) > 1:
                return float('inf') # 发现错误，把它传回来
            else:
                return max(leftHeight, rightHeight) + 1

        return checkHeight(root) != float('inf')
```
### 复杂度分析
- 时间复杂度：$O(N)$，$N$ 为节点的个数。
- 空间复杂度：$O(H)$，$H$ 为树的高度。