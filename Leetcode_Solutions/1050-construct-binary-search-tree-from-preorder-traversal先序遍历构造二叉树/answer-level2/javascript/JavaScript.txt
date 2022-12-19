### 解题思路
数组的第一项是根节点的值，不断递归即可
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
 * @param {number[]} preorder
 * @return {TreeNode}
 */
var bstFromPreorder = function(preorder) {
    const len = preorder.length
    if (!len) {
        return null
    }
    const left = []
    const right = []
    const rootVal = preorder[0]
    const root = new TreeNode(rootVal)
    for (let i = 1; i < len; i++) {
        const nodeVal = preorder[i]
        nodeVal > rootVal ? right.push(nodeVal) : left.push(nodeVal)
    }
    root.left = bstFromPreorder(left)
    root.right = bstFromPreorder(right)
    return root
};
```