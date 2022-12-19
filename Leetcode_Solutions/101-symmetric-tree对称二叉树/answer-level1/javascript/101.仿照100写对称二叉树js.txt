解题思路：
题目100
传入两个节点a,b，比较两个节点值是否相等
相等继续比较a节点的左节点是否与b节点的左节点相等；a节点的右节点是否与b节点的右节点相等。

题目101
传入两个节点a,b，比较两个节点值是否相等
相等继续比较a节点的右节点是否与b节点的左节点相等；a节点的左节点是否与b节点的右节点相等。
```
var solve = function(roota, rootb){
    var ans = true;
    (function (roota, rootb) {
        if(!roota && !rootb) return;
        if(roota && rootb){
            if(roota.val == rootb.val){
                arguments.callee(roota.left, rootb.right);
                arguments.callee(roota.right, rootb.left);
            }else{
                ans = false;
                return;
            }
        }else{
            ans = false;
            return;
        }
    })(roota, rootb)
    return ans;
}
var isSymmetric = function(root) {
    return solve(root, root);
};
```
