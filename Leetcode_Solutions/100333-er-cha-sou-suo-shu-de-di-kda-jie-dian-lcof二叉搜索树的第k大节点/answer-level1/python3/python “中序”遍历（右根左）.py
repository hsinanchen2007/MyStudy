修改中序遍历，先访问右子树，访问根，再访问左子树， 那么得到的序列是递减的，如果访问到了第k个节点， 即返回

```
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        if not root: return 
        stack = []
        res = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.right
            root = stack.pop()
            res.append(root.val)
            if len(res)==k: return res[-1]
            root = root.left
        return
```

