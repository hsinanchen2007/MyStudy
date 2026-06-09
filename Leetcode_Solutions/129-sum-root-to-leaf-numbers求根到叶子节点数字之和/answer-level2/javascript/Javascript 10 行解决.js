### 解题思路
递归遍历二叉树，同时记录路径数值，遇到叶子节点计算路径和。

### 代码

```javascript
var sumNumbers = function(root) {
    if (!root) return 0
    let sum = 0
    recurse(root, 0)
    return sum

    function recurse(root, cur) {
        cur = cur*10 + root.val
        if (!root.left && !root.right) sum += cur
        if (root.left) recurse(root.left, cur)
        if (root.right) recurse(root.right, cur)
    }
};
```