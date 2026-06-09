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
var isBalanced = function (root) {
    let ans = true;
    const dfs = (root) => {
        if (!root) return 0;
        let left = dfs(root.left);
        let right = dfs(root.right);
        if (Math.abs(left - right) > 1) ans = false;
        return Math.max(left, right) + 1;
    }
    dfs(root);
    return ans;
};

```