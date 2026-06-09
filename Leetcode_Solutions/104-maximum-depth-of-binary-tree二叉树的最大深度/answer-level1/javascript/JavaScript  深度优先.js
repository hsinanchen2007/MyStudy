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
 * @return {number}
 * 深度优先
 */
var maxDepth = function(root) {
    let max = 0;
    if (!root)
        return 0;
    const traverseTree = function(node, step) {
        if (node.left) {
            traverseTree(node.left, step + 1);
        }
        if (node.right) {
            traverseTree(node.right, step + 1);
        }
        if (step > max) {
            max = step;
        }
    }
    traverseTree(root, 1);
    return max;
};
```