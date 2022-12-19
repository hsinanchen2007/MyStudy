```
var buildTree = function(preorder, inorder) {
  if(!preorder.length&&!inorder.length) return null;
  let root=new TreeNode(preorder[0]);
  //i是中序遍历中根节点的位置，将左子树和右子树分开，同时也是左子树节点的个数
  let i=inorder.indexOf(preorder[0])>=0?inorder.indexOf(preorder[0]):0;
  //左子树的前序遍历和中序遍历
  root.left=buildTree(preorder.slice(1,i+1),inorder.slice(0,i));
  //右子树的前序遍历和中序遍历
  root.right=buildTree(preorder.slice(i+1),inorder.slice(i+1))
  return root
};
```
