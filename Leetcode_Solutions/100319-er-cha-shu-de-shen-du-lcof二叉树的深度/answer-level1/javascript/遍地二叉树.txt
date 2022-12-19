### 解题思路
递归遍历二叉树两边节点，返回大的值+1

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
var maxDepth = function(root) {
    if(!root)return 0;
    let left = maxDepth(root.left);
    let right = maxDepth(root.right);
    return 1+(left>right?left:right);
};
```