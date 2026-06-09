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
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    if (!inorder.length || !postorder.length) {
        return null
    }
    const root = new TreeNode(postorder[postorder.length - 1])
    const i = inorder.indexOf(root.val)
    root.left = buildTree(inorder.slice(0, i), postorder.slice(0, i))
    root.right = buildTree(inorder.slice(i + 1), postorder.slice(i, postorder.length - 1))
    return root
};
```