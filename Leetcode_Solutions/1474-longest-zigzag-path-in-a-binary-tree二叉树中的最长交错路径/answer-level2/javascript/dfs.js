### 解题思路
dfs

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
var longestZigZag = function(root) {
    if(root == null) return 0
    let ans = 0
    function dfs(node, dir, count) {
        if(node == null) return
        ans = Math.max(ans, count)
        if(!dir) { // 如果是左节点
            dfs(node.left, 0, 1)
            dfs(node.right, 1, count + 1)
        } else {
            dfs(node.left, 0, count + 1)
            dfs(node.right, 1, 1)
        }
    }
    dfs(root.left, 0, 1)
    dfs(root.right, 1, 1)
    return Math.max(0, ans)
}; 
```