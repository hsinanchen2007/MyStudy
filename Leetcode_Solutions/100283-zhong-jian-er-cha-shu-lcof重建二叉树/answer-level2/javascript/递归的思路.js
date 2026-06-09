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
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    if(!preorder.length || !inorder.length) {
        return null;
    }
    let root = preorder[0];
    let node = new TreeNode(root);
    let i = 0;
    for(;i<inorder.length;i++){
        if(inorder[i] === root) {
            break;
        }
    }
    node.left = buildTree(preorder.slice(1,i+1), inorder.slice(0,i));
    node.right = buildTree(preorder.slice(i+1), inorder.slice(i+1));
    return node;
};
```