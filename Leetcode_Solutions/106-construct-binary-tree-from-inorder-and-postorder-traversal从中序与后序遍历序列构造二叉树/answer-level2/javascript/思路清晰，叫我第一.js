
```js
var buildTree = function(inorder, postorder) {
    if(inorder.length == 0  || postorder.length == 0) return null
    let root = {
        val: postorder[postorder.length - 1],
        left: null,
        right: null
    }
    
    if(inorder.length == 1 || postorder.length ==1) return root

    let i = inorder.indexOf(root.val)

    root.left = buildTree(inorder.slice(0,i), postorder.slice(0,i))
    root.right = buildTree(inorder.slice(i+1), postorder.slice(i, postorder.length-1))

    return root
};
```