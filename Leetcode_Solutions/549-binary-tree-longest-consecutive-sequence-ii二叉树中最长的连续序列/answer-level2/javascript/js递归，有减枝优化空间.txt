```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var longestConsecutive = function(root) {
    if(!root){
        return 0;
    }
    var res = 0;
    // max是max(left.decrease + right.increase,right.decrease + left.increase) + 1
    function dfs(node){
        var tmp = Math.max(increase(node,node.left,0)+decrease(node,node.right,0),
        decrease(node,node.left,0)+increase(node,node.right,0)
        ) + 1;
        res = Math.max(tmp,res);
        node.left && dfs(node.left);
        node.right && dfs(node.right);
    }
    function increase(preNode,currentNode,path){
        if(!currentNode || (currentNode.val != preNode.val+1) ){
            return path;
        }
        return Math.max(increase(currentNode,currentNode.left,path+1),increase(currentNode,currentNode.right,path+1))
    }

    function decrease(preNode,currentNode,path){
        if(!currentNode ||  ( currentNode.val != preNode.val-1) ){
            return path;
        }
        return Math.max(decrease(currentNode,currentNode.left,path+1),decrease(currentNode,currentNode.right,path+1))
    }
    dfs(root);
    return res;
};
```
