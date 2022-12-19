偶数层从左至右，奇数层从右至左
```js
var zigzagLevelOrder = function(root) {
    var res = [];
    dfs(0, root);
    return res;
    function dfs(i, root){
        if(!root) return;
        if(!Array.isArray(res[i])) res[i] = [];
        if(i & 1) res[i].unshift(root.val);
        else res[i].push(root.val);
        dfs(i+1, root.left);
        dfs(i+1, root.right);
    }
};
```