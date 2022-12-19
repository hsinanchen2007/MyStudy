## 解题思路：
核心思想是DFS,利用深度优先遍历来解决问题。对于二叉树而言，需要判断的状态只有路径中的节点存在左子节点或者右子节点为空的情况，以及路径到达叶子节点的情况。
代码：
```javascript
var hasPathSum = function(root, sum) {
    if (!root)  return false;
    if (!root.left && !root.right)  return root.val === sum;
    return hasPathSum(root.left, sum-root.val) || hasPathSum(root.right, sum-root.val);
};
```
