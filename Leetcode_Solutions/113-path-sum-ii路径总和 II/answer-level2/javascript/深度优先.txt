```js
var pathSum = function(root, sum) {
    var res = [];
    dfs(root, [], 0);
    return res;
    function dfs(root, [...arr], accumulate){
        if(!root) return;
        accumulate += root.val;
        arr.push(root.val);
        if(!root.left && !root.right && accumulate === sum){
            res.push(arr);
        }
        dfs(root.left, arr, accumulate);
        dfs(root.right, arr, accumulate);
    }
};
```