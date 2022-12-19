### 解题思路
递归，使用try catch来判断子树是否相同

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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */

var isSameTree = function(p, q) {
    if(!p && !q) {
        return true
    }
    try {
        if(p.val !== q.val) {
            return false
        }
    } catch(e) {
        return false
    }
    const left = isSameTree(p.left, q.left)
    const right = isSameTree(p.right, q.right)
    return left && right
};
```