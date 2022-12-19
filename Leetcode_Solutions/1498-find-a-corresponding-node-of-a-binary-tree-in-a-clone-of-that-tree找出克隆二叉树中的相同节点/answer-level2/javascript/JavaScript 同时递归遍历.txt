```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} original
 * @param {TreeNode} cloned
 * @param {TreeNode} target
 * @return {TreeNode}
 */

var getTargetCopy = function(original, cloned, target) {
    // console.log(cloned)
    // console.log(target)
    if (original == target) {
        return cloned;
    } else {
        if (original.left !== null) {
            let r = getTargetCopy(original.left, cloned.left, target);
            if (r !== null) {
                return r;
            }
        }
        if (original.right !== null) {
            let r = getTargetCopy(original.right, cloned.right, target);
            if (r !== null) {
                return r;
            }
        }
        return null;
    }
};
```