### 解题思路
在还没操作节点右子树前，不能破坏该节点的右子树指向。所以采用后序遍历
```
void traverse(TreeNode root) {
    // 前序遍历
    traverse(root.left)
    // 中序遍历
    traverse(root.right)
    // 后序遍历
}
```
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def solve(n):
            if not n: return
            nonlocal pre
            solve(n.right)
            solve(n.left)
            n.right, n.left = pre, None
            pre = n
        pre = None
        solve(root)
        
```