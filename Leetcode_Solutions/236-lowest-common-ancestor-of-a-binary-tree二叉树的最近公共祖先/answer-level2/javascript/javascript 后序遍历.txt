javascript 后序遍历

fun返回的结果是 该节点是否是p或q的父节点。
如果当前节点是p或q，则只要有一个子节点是p或q的父节点，当前节点就是结果，否则返回true；
如果当前节点不是p或q，两个子节点都是p或q的父节点，则当前节点就是结果，否则返回子节点是否有至少一个p或q的父节点
```javascript
var lowestCommonAncestor = function(root, p, q) {
    let fun=function(node){
        if(!node) return false
        let left=fun(node.left)
        let right=fun(node.right)
        if(node===p||node===q){
            if(left|right) throw node
            else return true
        }
        else{
            if(left&right) throw node
            else return left^right
        }
    }
    try{
        return fun(root)
    }
    catch(e){
        return e
    }
};
```

