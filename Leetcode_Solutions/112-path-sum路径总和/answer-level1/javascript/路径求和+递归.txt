### 解题思路


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
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    if (root === null) {
        return false
    }
    sum -= root.val
    if (root.left === null && root.right === null) {
        return sum === 0
    } else {
        return hasPathSum(root.left, sum) || hasPathSum(root.right, sum)
    }
    
};
```