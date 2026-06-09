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
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    let res = 0
    function getHeight (root) {
        if (!root) {
            return 0
        }
        const left = root.left ? getHeight(root.left) + 1 : 0
        const right = root.right ? getHeight(root.right) + 1 : 0
        res = Math.max(left + right, res)
        return Math.max(left, right)
    }
    getHeight(root)
    return res
};
```