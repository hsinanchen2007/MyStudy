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
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    if (!root) return [];
    if (!root.left && !root.right) return [root.val];
    let res = [];
    function inorder (root) {
        if (root) {
            inorder(root.left);
            res.push(root.val);
            inorder(root.right);
        }
    }
    inorder(root);
    return res;
};
```