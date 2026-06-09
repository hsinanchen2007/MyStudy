1.中序遍历二叉搜索树得到升序数组res，返回第k个值即可；
2.进阶：提前截断中序遍历，即判断结果数组res的长度和k的值,如果res.length>=k则不再遍历，从而提高效率
```
var kthSmallest = function(root, k) {
    let res = [];
    function lnr(node){
        if(node && res.length<k){
            lnr(node.left);
            res.push(node.val);
            lnr(node.right);
        }
    }
    lnr(root);  
    return res[k-1];
};
```
