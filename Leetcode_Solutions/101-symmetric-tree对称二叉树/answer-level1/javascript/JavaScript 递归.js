### 解题思路
对称：如果一个树的左子树与右子树镜像对称，那么这个树是对称的。
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
    return __isSymmetric(root.left, root.right);
};

function __isSymmetric(t1, t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (
        t1.val === t2.val &&
        __isSymmetric(t1.left, t2.right) &&
        __isSymmetric(t1.right, t2.left)
    );
}
```