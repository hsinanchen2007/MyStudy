#在递归遍历的时候带上层次参数，直接将结果输出值指定位置

1.代码逻辑很直接，对应的人的直观思维，直接将第k层的数据放入第k个数组中。
2.JavaScript的数组是动态的，所以我们不需要提前考虑有多少层，也不需要考虑每层有多少个数据。
```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    var layers = [];
    search(layers, root, 0);
    return layers;
};

/**
 * 带层次递归遍历
 * @param layers    输出
 * @param node      二叉树节点
 * @param k         层次
 */
function search(layers, node, k) {
    if (node == null) {
        return;
    }
    if (layers[k] == undefined) {
        layers[k] = [node.val];
    }else {
        layers[k].push(node.val);
    }
    search(layers, node.left, k + 1);
    search(layers, node.right, k + 1);
}
```
