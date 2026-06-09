### 解题思路
思路清晰，叫我第一☝️（dfs专练）

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
 * @return {boolean}
 */
let isans
var isBalanced = function(root) {
    isans = true
    dfs(root)
    return isans
};

var dfs = function(root){
    if(!root) return 0
    let left = dfs(root.left),
        right = dfs(root.right)
    if(Math.abs(left - right) > 1) isans = false
    return Math.max(left, right) + 1
}
```