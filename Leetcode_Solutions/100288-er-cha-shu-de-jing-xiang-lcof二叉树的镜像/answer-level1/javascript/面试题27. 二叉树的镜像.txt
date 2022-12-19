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
 * @return {TreeNode}
 */
var mirrorTree = function(root) {
    if(!root){
        return null
    }
    let tmp = root.right
    root.right = mirrorTree(root.left)
    root.left = mirrorTree(tmp)
    return root
};
```