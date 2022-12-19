### 解题思路

后序遍历 
当前节点深度 = 子节点最大深度 + 1

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
var maxDepth = function (root) {
    if (root === null) return 0;

    const left = maxDepth(root.left);
    const right = maxDepth(root.right);
    const dep = Math.max(left, right) + 1;
    return dep;
};
```