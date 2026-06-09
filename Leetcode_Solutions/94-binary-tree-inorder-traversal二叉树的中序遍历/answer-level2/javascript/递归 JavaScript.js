![image.png](https://pic.leetcode-cn.com/e56c270302d9eec2d8670eca11d6351dbbeb65496ca18b1e5df663b453b34916-image.png)

```
var inorderTraversal = function(root) {
    if (!root)
        return [];
    return inorderTraversal(root.left).concat([root.val], inorderTraversal(root.right));
}
```
