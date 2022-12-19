### 解题思路
分割左右子树，递归

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
    if(preorder.length==0) return null;
    let root = preorder[0];     //取根节点
    let tree=new TreeNode(root);  //new一个树，最上面有 TreeNode的结构
    let i = inorder.indexOf(root);
    console.log(preorder.slice(1,i+1))

    // slice(start,end)   //分割左右子树，递归
    //slice(len)         //切掉前len个
    tree.left=buildTree(preorder.slice(1, i + 1), inorder.slice(0, i));
    tree.right = buildTree(preorder.slice(i + 1), inorder.slice(i + 1));
    
    return tree;
};

```