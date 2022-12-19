### 解题思路

一、递归：左 中 右

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
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    let res = [];
    function pushRoot (root) {
        if (root != null) {
            if (root.left != null) {
                pushRoot(root.left);
            }
            res.push(root.val);
            if (root.right != null) {
                pushRoot(root.right);
            }
        }
    }
    pushRoot(root);
    return res;
};
```