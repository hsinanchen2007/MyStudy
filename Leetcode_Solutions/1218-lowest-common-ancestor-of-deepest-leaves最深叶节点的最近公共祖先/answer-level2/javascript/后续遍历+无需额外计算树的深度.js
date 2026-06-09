- 一棵节点的左右子树的深度都等于最大深度 则这个节点就有可能是结果 最终的结果肯定是最靠近根节点 切满足条件的节点 所以需要采用后续遍历
```
var lcaDeepestLeaves = function (root) {
  let res = root;
  let maxDepth = 0;
  let dfs = function (root, depth) {
    if (!root) return depth - 1;
    let leftDepth = dfs(root.left, depth + 1)
    let rightDepth = dfs(root.right, depth + 1)
    maxDepth = Math.max(maxDepth, leftDepth, rightDepth)
    if (leftDepth === maxDepth && rightDepth === maxDepth) {
      res = root;
    }
    return Math.max(leftDepth, rightDepth);
  }
  dfs(root, 0);
  return res;
};
```
