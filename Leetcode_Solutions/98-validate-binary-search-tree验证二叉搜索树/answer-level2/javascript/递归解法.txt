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
 * @return {boolean}
 */
var isValidBST = function(root) {

    if (!root) return true

    prev = null, isValid = true
    dfs(root)

    return isValid
};

const dfs = node => { // Depth-First-Search 深度优先搜索
    if (node) {
        dfs(node.left)
        if (prev && prev.val >= node.val) {
            isValid = false
            return
        }
        prev = node
        dfs(node.right)
    }
};
```