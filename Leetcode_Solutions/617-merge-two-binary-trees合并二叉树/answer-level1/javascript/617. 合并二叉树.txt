### 解题思路
递归

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
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */
var mergeTrees = function (t1, t2) {
    if (t1 === null && t2 === null) {
        return null
    }
    let node = new TreeNode((t1 ? t1.val : 0) + (t2 ? t2.val : 0))
    node.left = mergeTrees(t1 ? t1.left : null, t2 ? t2.left : null)
    node.right = mergeTrees(t1 ? t1.right : null, t2 ? t2.right : null)
    return node
};
```