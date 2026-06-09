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
var isValidBST = function (root) {

    function helper(root, upper, lower) {
        if (!root) {
            return true
        }
        else if (root.val >= upper || root.val <= lower) {
            console.log(root.val)
            return false
        }
        return helper(root.left, root.val, lower) && helper(root.right, upper, root.val)
    }

    return helper(root, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY)
};
```