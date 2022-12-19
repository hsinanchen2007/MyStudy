### 解题思路

嗯，递归很简单

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
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    let res = []

    if (!root) return  res

    function loop(tree) {
        res.push(tree.val)
        tree.left && loop(tree.left)
        tree.right && loop(tree.right)
    }

    loop(root)

    return res
};
```