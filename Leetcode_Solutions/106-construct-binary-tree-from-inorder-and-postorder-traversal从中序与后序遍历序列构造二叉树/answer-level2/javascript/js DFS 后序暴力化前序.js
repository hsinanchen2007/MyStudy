```
var buildTree = function(inorder, postorder) {
    function dfs(preorder, inorder) {
        if(!preorder.length || !inorder.length) return null;
        if(inorder.length === 1) return new TreeNode(inorder[0]);
        const root = new TreeNode(preorder[0]);
        const index = inorder.indexOf(root.val);
        const len = inorder.length - index;
        root.left = dfs(preorder.slice(len), inorder.slice(0, index));
        root.right = dfs(preorder.slice(1, len), inorder.slice(index + 1));
        return root;
    }
    return dfs(postorder.reverse(), inorder);
};
```
