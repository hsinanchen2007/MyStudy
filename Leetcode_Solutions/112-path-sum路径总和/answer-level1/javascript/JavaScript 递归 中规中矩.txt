```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 * 递归依次往下，判断好退出条件是走到子节点
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    const hasPathSub = (node, currentSum) => {
        if (!node)
            return false;
        if (node.val + currentSum === sum && !node.left && !node.right)
            return true;
        return hasPathSub(node.left, node.val + currentSum) || hasPathSub(node.right, node.val + currentSum)
    }
    return hasPathSub(root, 0);
};
```