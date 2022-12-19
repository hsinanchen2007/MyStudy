```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isUnivalTree = function(root, val) {
    val === undefined && (val = root.val)
    return !root.left && !root.right ? root.val === val : root.val === val && (root.left ? isUnivalTree(root.left, val) : true) && (root.right ? isUnivalTree(root.right, val) : true)
};
```
