时间空间最优解
```js
var searchBST = function(root, val) {
    if(root == null) return null;
    if(root.val == val) return root;
    return root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
};
```
