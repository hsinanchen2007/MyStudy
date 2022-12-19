### 解题思路

递归中序

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
    if(root === null) {
        return [];
    }

    let list = [];
    list.push(...inorderTraversal(root.left));
    list.push(root.val);
    list.push(...inorderTraversal(root.right));
    return list;
};
```