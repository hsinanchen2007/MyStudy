### 解题思路
分割左右子树，递归建树

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
// preorder:val,left,right,
// inorder: left,val,right
    if(preorder.length==0) return null
    let root=preorder[0]
    let tree=new TreeNode(root)
    let i=inorder.indexOf(root)   //分割左右子树，递归建树
    tree.left=buildTree(preorder[1,1+i],  inorder[0,i-1])
    tree.right= buildTree(preorder[i+2,-1],inorder[i,-1])
    return tree
};
