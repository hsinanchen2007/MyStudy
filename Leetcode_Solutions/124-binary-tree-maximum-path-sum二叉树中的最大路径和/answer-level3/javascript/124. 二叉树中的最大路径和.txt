# 思路
取一个节点，通常有两种情况：
- 以这个节点为拐点向这个节点的父节点路由，这种情况下仅需要得到该节点左右两支中交大的一支加上当前节点即可
- 以这个节点为拐点向这个节点的另一子节点路由，这种情况下，只需要左右两支加上当前节点即可
接下来递归就好了~
注意：其中要对负数节点进行剪枝~

## 第一种思路
想的是把所有节点为拐点的极值存放到一个数据集中，最后对数据集求极值即可~
```
var maxPathSum = function(root) {
    let resultArr = [];
    let helper = function(node){
        if(node == null) return 0;
        let leftPathVal = Math.max(helper(node.left), 0);
        let rightPathVal = Math.max(helper(node.right), 0);
        resultArr.push(leftPathVal+rightPathVal+node.val)
        return Math.max(leftPathVal,rightPathVal)+node.val;
    }
    resultArr.push(helper(root));
    return Math.max.apply(null,resultArr);
};
```
## 第二种思路
其实就是对上边的数据集进行优化，仅保存一个最大值，每次求得该节点下极值时就与保存极值进行比较~
```
var maxPathSum = function(root) {
    let maxSum = -Infinity;
    let helper = function(node){
        if (node == null) return 0;
        let leftVal = Math.max(helper(node.left), 0);
        let rightVal = Math.max(helper(node.right), 0);
        let newPath = node.val + leftVal + rightVal;
        maxSum = Math.max(maxSum, newPath);
        return node.val + Math.max(leftVal, rightVal);
    }
    helper(root);
    return maxSum;
};
```

