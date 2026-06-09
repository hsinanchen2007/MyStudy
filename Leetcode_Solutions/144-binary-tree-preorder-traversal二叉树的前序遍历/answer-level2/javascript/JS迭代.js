迭代：利用栈特性，后进先出
```js
var preorderTraversal = function(root) {
    /*//递归
    var res = [];
    dfs(root);
    return res;
    function dfs(root){
        if(!root) return;
        res.push(root.val);
        dfs(root.left);
        dfs(root.right);
    }*/
    var res = [];
    if(!root) return res;
    var stack = [root];
    while(stack.length !== 0){
        var node = stack.pop();
        res.push(node.val);
        if(node.right){
            stack.push(node.right);
        }
        if(node.left){
            stack.push(node.left);
        }
    }
    return res;
};
```