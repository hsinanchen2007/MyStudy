```
var buildTree = function(preorder, inorder) {
    if(!preorder.length || !inorder.length) return null;
    if(inorder.length === 1) return new TreeNode(inorder[0]);
    const root = new TreeNode(preorder[0]);
    const index = inorder.indexOf(root.val);
    root.left = buildTree(preorder.slice(1, index + 1), inorder.slice(0, index));
    root.right = buildTree(preorder.slice(index + 1), inorder.slice(index + 1));
    return root;
};
```
