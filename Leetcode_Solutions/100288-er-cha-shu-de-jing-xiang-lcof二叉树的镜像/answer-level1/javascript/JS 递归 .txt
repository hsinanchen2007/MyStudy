### 代码

```javascript
var mirrorTree = function(root) {
    // 判断根节点
    if(root == null) return root;
    // 交换左右子树
    [root.left, root.right] = [root.right, root.left];
    // 递归交换左右子树
    mirrorTree(root.left);
    mirrorTree(root.right);
    return root
};
```