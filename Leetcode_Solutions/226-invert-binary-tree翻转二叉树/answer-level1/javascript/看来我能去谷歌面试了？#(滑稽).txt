### 解题思路
就是左右节点互换
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
var invertTree = function (root) {
    function fz(root) {
        if (root === null) return root;
        let left = fz(root.left);
        let right = fz(root.right);  
        root.left = right;
        root.right = left;
        // let left = JSON.parse(JSON.stringify(root.left));
        // root.left = fz(root.right);
        // root.right = fz(left);
        return root;
    }
    return fz(root)
};
```