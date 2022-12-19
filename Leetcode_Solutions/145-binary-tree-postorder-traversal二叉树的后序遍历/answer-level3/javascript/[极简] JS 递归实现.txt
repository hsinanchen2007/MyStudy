```
let preNode = function (root,arr){
    if(!root) return [];
    preNode(root.left,arr);
    preNode(root.right,arr);
    arr.push(root.val);
}
var postorderTraversal = function(root) {
    if(!root) return [];
    let arr =[];
    preNode(root,arr);
    return arr
};
```

之前我写过一篇题解是二叉树的前序遍历的，二叉树的遍历使用递归完成都是比较简单的
如果是前序那么我们只需要改变一下遍历的顺序就可以了
```
let preNode = function (root,arr){
    if(!root) return [];
    arr.push(root.val);
    preNode(root.left,arr);
    preNode(root.right,arr);
}
```
如果是中序，那么也是大同小异
```
let preNode = function (root,arr){
    if(!root) return [];
    preNode(root.left,arr);
    arr.push(root.val);
    preNode(root.right,arr);
}
```
对于二叉树的遍历，使用递归都是比较好写的
不过层级遍历，可能需要一个队列，比先中后序遍历稍微麻烦一点

欢迎讨论
👏👏👏

