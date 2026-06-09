https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
大家可以做做这道题，跟这个差不多，只是增加了个要求。（leetcode 637.二叉树的平均值）
```
var levelOrder = function(root) {
    if(!root) return []
    let queue=[root];
    let res=[];
    while(queue.length){
        let node=queue.shift();
        res.push(node.val);
        if(node.left) queue.push(node.left);
        if(node.right) queue.push(node.right)
      }
    return res
};
```
