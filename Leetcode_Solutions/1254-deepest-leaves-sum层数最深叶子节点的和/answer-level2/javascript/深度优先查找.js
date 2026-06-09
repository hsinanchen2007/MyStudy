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
 * @return {number}
 */

var deepestLeavesSum = function(root) {
    // 深度遍历
    var maxDeepth = 0;
    var maxDeepthSum = 0;

    var dfs = function (node, depth) {
        if (!node) {
            return;
        }

        if (depth == maxDeepth) {
            maxDeepthSum += node.val;
        } else if (depth > maxDeepth) {
            maxDeepth = depth;
            maxDeepthSum = node.val;
        }
 
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    dfs(root, 1);

    return maxDeepthSum;
};
```