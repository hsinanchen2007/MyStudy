```
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
var isUnivalTree = function (root) {
    function check(parent, node) {
        if (node) {
            if (parent.val === node.val) {
                return check(node, node.left) && check(node, node.right)
            } else {
                return false;
            };
        }
        return true;
    }
    return check(root, root.left) && check(root, root.right);
};
```

