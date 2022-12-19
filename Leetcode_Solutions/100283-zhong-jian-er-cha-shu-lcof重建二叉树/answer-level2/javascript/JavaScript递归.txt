### 代码
```javascript
var buildTree = function(preorder, inorder) {
    var result = null;
    if(preorder.length > 1){
        var index = inorder.indexOf(preorder[0]);
        result = {
            val: preorder[0],
            left: buildTree(preorder.slice(1, index + 1), inorder.slice(0, index)),
            right: buildTree(preorder.slice(index + 1), inorder.slice(index + 1))
        }
    }else if(preorder.length == 1){
        result = {
            val: preorder[0],
            left: null,
            right: null
        }
    }
    return result;
};
```