### 解题思路
五行，简单的递归实现

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
var inorderTraversal = function (root, arr = []) {
    if (!root) return []
    root.left && inorderTraversal(root.left, arr);
    arr.push(root.val);
    root.right && inorderTraversal(root.right, arr);
    return arr
};
```