* 欲求整棵树的深度，等价于 当前树根节点的深度 + max(左子树的深度， 右子树的深度)， 截止条件为遇到空节点
```
var maxDepth = function(root) {
  if(root === null) return 0
  return 1 + Math.max(maxDepth(root.left), maxDepth(root.right))
};
```
