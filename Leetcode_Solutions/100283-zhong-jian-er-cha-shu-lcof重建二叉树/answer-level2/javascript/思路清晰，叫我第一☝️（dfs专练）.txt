### 解题思路
思路清晰，叫我第一☝️（dfs专练）

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
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    if(preorder.length == 0 || inorder.length == 0) return null

    let root = {
        val: preorder[0],
        left : null,
        right: null
    }
    let i = inorder.indexOf(preorder[0])

    root.left = buildTree(preorder.slice(1, 1 + i), inorder.slice(0, i))
    root.right = buildTree(preorder.slice(1 + i), inorder.slice(i+1))

    return root
};
```