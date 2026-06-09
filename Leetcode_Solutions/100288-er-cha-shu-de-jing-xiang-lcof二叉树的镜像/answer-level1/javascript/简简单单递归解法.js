### 解题思路
此处撰写解题思路

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
 * @return {TreeNode}
 */
var mirrorTree = function(root) {

    if (!root) return null

    let left = mirrorTree(root.left),
        right = mirrorTree(root.right)

    root.left = right
    root.right = left

    return root
};
```