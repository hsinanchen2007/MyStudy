递归遍历树的所有节点，删除某个节点的时候，将其左、右节点放入到结果数组中即可，但是需要注意，若其左右节点也在`to_delete`中那么不能将其记录到`result`·`中，别忘了根节点也需要做一下判断~  

*技巧：将`to_delete`转换为一个`Set`可以优化速度*

```js
var delNodes = function(root, to_delete) {
    let result = [];
    let needDelete = new Set(to_delete);
    if(!needDelete.has(root.val)){
        result.push(root);
    }
    
    tools(root,needDelete,{left:root});
    return result;
    
    function tools(node,needDelete,p){
        if(!node)return ;
        if(needDelete.has(node.val)){
            node.left && !needDelete.has(node.left.val) && result.push(node.left)
            node.right && !needDelete.has(node.right.val) && result.push(node.right);
        }
        node.left && tools(node.left,needDelete,node);
        node.right && tools(node.right,needDelete,node);
        if(needDelete.has(node.val)){
            node===p.left?p.left=null:p.right=null;    
        }
    }
};
```