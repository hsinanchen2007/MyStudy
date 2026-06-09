找出通项公式，递归就完事了

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
 * @param {number} target
 * @return {TreeNode}
 */
var removeLeafNodes = function(root, target) {
    let fn = (root) => {
        if (root === null) return null
        root.left = fn(root.left)
        root.right = fn(root.right)
        if (root.val === target && root.left === null && root.right === null) {
            return null
        } else {
            return root
        }
    }
    return fn(root)
};
```
