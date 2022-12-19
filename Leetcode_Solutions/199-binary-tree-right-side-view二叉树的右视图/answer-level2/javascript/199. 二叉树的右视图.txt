# BFS
简单粗暴递归广度优先拿到整个数的二位值平铺~
然后遍历拿到每一层最后一个值
```
var rightSideView = function(root) {
    if(root == null) return [];
    let arr = [];
    let helper = function(node,index){
        if(!(arr[index] instanceof Array)){
           arr[index] = [];
        }
        if(node.left != null){
            helper(node.left,index+1)
        }
        if(node.right != null){
            helper(node.right,index+1)
        }
        arr[index].push(node.val);
    }
    helper(root,0);
    let result = [];
    for(let i = 0,len = arr.length;i<len;i++){
        result.push(arr[i].pop());
    }
    return result;
```
