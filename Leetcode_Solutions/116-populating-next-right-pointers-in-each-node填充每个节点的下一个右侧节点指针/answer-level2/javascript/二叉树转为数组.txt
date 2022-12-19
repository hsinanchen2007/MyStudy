```js
var connect = function(root) {
    var res = [];
    dfs(root, 0);
    for(var i=0;i<res.length;i++){
        for(var j=0;j<res[i].length;j++){
            if(j < res[i].length-1){
                res[i][j].next = res[i][j+1];
            }
        }
    }
    if(res.length === 0) return root;
    return res[0][0];
    function dfs(root, n){
        if(!root) return;
        if(!Array.isArray(res[n])) res[n] = [];
        res[n].push(root);
        dfs(root.left, n+1);
        dfs(root.right, n+1);
    }
};
```