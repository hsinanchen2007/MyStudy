递归返回左右子树的最大深度

```
var maxDepth = function(root, deep = 0) {
    if (!root) return deep
    if (root.left === null && root.right === null) return deep + 1
    return Math.max(maxDepth(root.left, deep + 1), maxDepth(root.right, deep + 1))
};
```