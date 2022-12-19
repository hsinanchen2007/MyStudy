```js
var bstFromPreorder = function(preorder) {
    return dfs(preorder);
    function dfs([...arr]){
        if(arr.length === 0) return null;
        var val = arr.shift();
        var node = new TreeNode(val);
        var idx = arr.length;
        for(var i=0;i<arr.length;i++){
            if(arr[i] > val){
                idx = i;
                break;
            }
        }
        var arr_left = arr.slice(0, idx);
        var arr_right = arr.slice(idx);
        node.left = dfs(arr_left);
        node.right = dfs(arr_right);
        return node;
    }
};
```