```
var minDepth = function(root) {
    if(root == null){                               //叶子节点值为0
        return 0;               
    }
    let l = minDepth(root.left);                    //先左后右
    let r = minDepth(root.right);
    if(root.left == null ||  root.right == null){   //如果只有左侧叶子节点或只有右侧叶子节点那么深度应该是2而不是1
        return l+r+1
    }
    return Math.min(l,r)+1                          //每个节点的值应该是其最小深度加上其本身
};
```
