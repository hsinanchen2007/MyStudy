```
var inorderSuccessor = function(root, p) {
    let arr = [];
    let dfs = (node) => {
        if(!node)return;
        dfs(node.left);
        arr.push(node.val);
        dfs(node.right);
    };
    dfs(root);
    if(arr.indexOf(p.val) === arr.length-1)return null;

    // 找节点
    let des = arr[arr.indexOf(p.val) + 1];
    let res;
    let fn = (node) => {
        if(!node)return;
        if(node.val === des){res = node;return }
        fn(node.left);
        fn(node.right);
    };
    fn(root);
    return res;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，