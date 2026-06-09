### 解题思路
单独写一个中序遍历的函数即可，递归其实就是固定的模板

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
 * @return {number[]}
 */
var inorderTraversal = function (root) {
    var result = [];
    inorderTraversalHelper(root, result);
    return result;
};

var inorderTraversalHelper = function (root, result) {
    if (root != null) {
        if (root.left != null) {
            inorderTraversalHelper(root.left, result);
        }
        result.push(root.val);
        if (root.right != null) {
            inorderTraversalHelper(root.right, result);
        }
    }
}
```