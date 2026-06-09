
```
var invertTree = function(root) {
    if(root !== null){
        [root.left, root.right] = [invertTree(root.right), invertTree(root.left)]
    }
    return root
};
```
