```
// DFS 递归
var isBalanced = function(root) {
    let res = true;
    function getDeep(root) {
        if(!res) return;
        if(!root) return 0;
        const leftDeth = getDeep(root.left) ;
        const rightDeth = getDeep(root.right);
        if(Math.abs(leftDeth - rightDeth) > 1) res = false;
        return Math.max(leftDeth, rightDeth) + 1;
    }
    getDeep(root);
    return res;
};
```
