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
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function(root, val) {
    if(root == null) return root
    if(root.val == val) return root
    return root.val < val ? searchBST(root.right, val) : searchBST(root.left, val)
};
```