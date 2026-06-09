```
// 递归 84 ms
var pathSum = function(root, sum) {
    function help(node, path, pathSum, arr){
        pathSum = pathSum + node.val        
        if(node.left == null && node.right == null && pathSum == sum){
            path.push(node.val)
            arr.push(path)
        }
        if(node.left != null){
            leftPath = path.concat()
            leftPath.push(node.val)
            help(node.left,leftPath,pathSum,arr)
        }
        if(node.right != null){
            rightPath = path.concat()
            rightPath.push(node.val)
            help(node.right,rightPath,pathSum,arr)
        }
    }
    if(root == null) return []
    let res = []
    help(root, [], 0, res)
    return res
};

// 迭代 128 ms
var pathSum = function(root, sum) {
    if(root == null) return []
    let res = []
    let node_stack = [root]
    let path_stack = [[root.val]]
    while(node_stack.length != 0){
        let curNode = node_stack.pop()
        let curPath = path_stack.pop()
        if((curNode.left == null) && (curNode.right == null)){
            if (eval(curPath.join("+")) == sum){
                res.push(curPath)
            }
        }
        if(curNode.left != null){
            node_stack.push(curNode.left)
            let leftPath = curPath.concat()
            leftPath.push(curNode.left.val)
            path_stack.push(leftPath)
        }
        if(curNode.right != null){
            node_stack.push(curNode.right)            
            let rightPath = curPath.concat()
            rightPath.push(curNode.right.val)
            path_stack.push(rightPath)
        }
    }
    return res        
};
```

