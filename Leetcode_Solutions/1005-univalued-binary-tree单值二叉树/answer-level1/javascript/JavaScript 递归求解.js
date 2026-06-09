### 解题思路
递归
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
var isUnivalTree = function(root) {
    if (!root) {
        return true 
    }
    const val = root.val
    function _isUnivalTree (root) {
        if (root) {
            if (root.val != val) {
                return false
            } else {
                return _isUnivalTree(root.left) && _isUnivalTree(root.right)
            }
        } else {
            return true
        }
    } 
    return _isUnivalTree(root)
};
```