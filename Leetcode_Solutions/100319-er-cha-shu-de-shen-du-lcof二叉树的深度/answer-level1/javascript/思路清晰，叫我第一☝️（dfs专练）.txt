### 解题思路
dfs专练

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
let max
var maxDepth = function(root) {
    max = 0
    dfs(root, 0)
    return max
};

var dfs = function(root, depth){
    if(!root){
        if(depth > max) max = depth
        return
    }
    depth++
    dfs(root.left, depth)
    dfs(root.right, depth)
}
```