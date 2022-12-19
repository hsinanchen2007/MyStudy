### 使用全局变量存储路径
```
var pathSum = function(root, sum) {
    if(!root) return [];
    // 先存储根节点
    let path = [root.val];
    let res = [];
    // 深度优先，朝着一个方向一条路径遍历
    let preorder = (node) => {
        // 存在左节点，遍历左边
        if(node.left) {
            path.push(node.left.val);
            preorder(node.left);
            // 遍历完，不管符不符合要求都弹出           
            path.pop();
        } 
        if(node.right) {
            path.push(node.right.val);
            preorder(node.right);           
            path.pop();
        }
        // 到达叶子节点，判断路径和
        if(!node.left && !node.right) {
            let add = 0;
            for(let i = 0; i < path.length; i++) {
                add += path[i];
            }
            if(add == sum) {
                // 不能使用 res.push(path)是因为path是全局变量，push进的是path的地址，而不是数组的值
                res.push(path.slice());
            }           
        }
    }
    preorder(root);
    return res;
};
```
### 大神的使用函数形参传递路径，不需要pop
```
var pathSum = function(root, sum) {

    const res = [];
    if(root == null){
        return res
    }

    function helper(node,target,paths){
        paths.push(node.val);
        //递归结束条件
        if(!node.left && !node.right && node.val === target){
            res.push(paths)
        }
        //使用slice进行浅拷贝
        //根据题目的例子
        //执行到 7 的时候 都不符合
        //它会回到11哪步，执行node.right
        //接着执行下面代码
        if(node.left){
            helper(node.left,target-node.val,paths.slice())
        }
        // 使用slice进行浅拷贝
        if(node.right){
            helper(node.right,target-node.val,paths.slice())
        }

    }

    helper(root,sum,[]);
    return res

};
```


