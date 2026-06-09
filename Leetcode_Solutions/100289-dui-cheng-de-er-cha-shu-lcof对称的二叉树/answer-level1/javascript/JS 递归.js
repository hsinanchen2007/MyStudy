### 代码

```javascript
var isSymmetric = function(root) {
    return root == null || judge(root.left, root.right) 
};

const judge = (node1, node2) => {
    if(node1 == null && node2 == null){
        return true
    }else if(node1 == null || node2 == null){
        return false
    }
    if(node1.val !== node2.val){
        return false
    }else{
        return judge(node1.left, node2.right) && judge(node1.right, node2.left)
    }
}
```