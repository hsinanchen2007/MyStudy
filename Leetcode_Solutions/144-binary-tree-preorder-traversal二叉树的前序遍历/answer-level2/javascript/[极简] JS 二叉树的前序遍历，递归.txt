树的遍历属于基础知识

对于二叉树的遍历而言，前中后序的遍历的主要逻辑是一样的
相对的，层级遍历稍微麻烦一点，因为要用到队列嘛

这里使用递归实现
```let preNode = function (root,arr){
    if(!root) return [];
    arr.push(root.val);
    preNode(root.left,arr);
    preNode(root.right,arr);
}
var preorderTraversal = function(root) {
    let arr = [];
    if(!root) return [];
    preNode(root,arr)
    return arr
};```

这里的preNode是前序

那么中序只需要稍微的修改即可
```let preNode = function (root,arr){
    if(!root) return [];
    preNode(root.left,arr);
    arr.push(root.val);
    preNode(root.right,arr);
}
```

相应的，后序则为

```let preNode = function (root,arr){
    if(!root) return [];
    preNode(root.left,arr);
    preNode(root.right,arr);
    arr.push(root.val);
}
```

总而言之递归思想还是很重要的，前中后序的变换主要区别是先跑哪一个节点，仅此而已

欢迎讨论
👏👏👏👏