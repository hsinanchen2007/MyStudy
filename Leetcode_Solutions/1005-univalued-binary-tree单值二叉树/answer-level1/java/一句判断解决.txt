
```js
var isUnivalTree = function(root) {
    if(root == null || root.left == null && root.right == null) {
        return true;
    } else if (root.left == null) { // root.right != null
        return root.val == root.right.val && isUnivalTree(root.right);
    } else if (root.right == null) { // root.left != null
        return root.val == root.left.val && isUnivalTree(root.left);
    } else { // root.left != null && root.right != null
        return root.left.val == root.val && root.right.val == root.val 
               && isUnivalTree(root.left) && isUnivalTree(root.right);
    }
};
```
