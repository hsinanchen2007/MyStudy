### 解题思路
此处撰写解题思路

### 代码

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
var isSymmetric = function(root) {
    if (!root) return true;
    if (root && !root.left && !root.right) return true;
    function compare(left, right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left.val === right.val
        && compare(left.left, right.right)
        && compare(left.right, right.left);
    }
    return compare(root, root);
    
};
```