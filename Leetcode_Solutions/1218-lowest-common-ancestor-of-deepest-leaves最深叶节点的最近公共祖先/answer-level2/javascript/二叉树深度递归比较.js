```js
//计算每个节点左右子树的高度，获取最深的节点的父节点
var lcaDeepestLeaves = function(root) {
    return dfs(root);
    function dfs(root){
        if(!root) return;
        var left = getDepth(root.left);
        var right = getDepth(root.right);
        if(left === right){
            return root;
        }else if(left > right){
            return dfs(root.left);
        }else{
            return dfs(root.right);
        }
    }
    function getDepth(node){
        if(!node) return 0;
        var l = getDepth(node.left);
        var r = getDepth(node.right);
        return Math.max(l, r)+1;
    }
};
```