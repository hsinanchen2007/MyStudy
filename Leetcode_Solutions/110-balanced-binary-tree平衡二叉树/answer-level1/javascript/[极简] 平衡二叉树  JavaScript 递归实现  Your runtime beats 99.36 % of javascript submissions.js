// 核心思路：
// 1，从左到右递归树的节点，记录节点的最大深度
// 2，在记录节点的同时对该树的节点的左子树与右子树的最大深度做一次对比，如果差值超过1则返回false

// ```
function isBalanced1(root,result){
    if(root == null){
        return 0
    }
    let l = isBalanced1(root.left,result);
    let r = isBalanced1(root.right,result);
    if(l-r>1 || l-r<-1){
        result[0] = false
    }
    return Math.max(l,r)+1;
}
var isBalanced = function(root) {
    let a = [true];
    isBalanced1(root,a);
    return a[0]
};

// ```

// 这里需要注意的是每次递归都要将返回的boolen带下去，这也是此代码中的一个可以优化的点。
// 欢迎讨论
// 👏👏👏
