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
var diameterOfBinaryTree = function(root) {
    this.len = 0;
    dfs(root);
    return this.len;
};

var dfs = function(root){
    if(!root) return 0;
    var l = dfs(root.left);
    var r = dfs(root.right);
    this.len = Math.max(l + r, this.len);
    return Math.max(l, r) + 1;
}

```