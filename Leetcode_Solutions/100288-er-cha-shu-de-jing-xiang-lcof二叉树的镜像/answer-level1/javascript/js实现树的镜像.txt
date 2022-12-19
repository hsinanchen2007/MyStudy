### 解题思路
代码如下

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
    if(root===null)return root;
    let tem=root.left;
    root.left=root.right;
    root.right=tem;
    mirrorTree(root.left);
    mirrorTree(root.right);

    return root;

};
```