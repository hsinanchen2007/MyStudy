js递归，代码简洁
```js
var mirrorTree = function(root) {
    if (root) {
        [root.left, root.right] = [mirrorTree(root.right), mirrorTree(root.left)];
    }
    return root;
};
```