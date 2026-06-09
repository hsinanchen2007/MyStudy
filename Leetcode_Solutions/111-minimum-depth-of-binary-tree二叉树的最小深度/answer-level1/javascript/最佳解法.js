```
var minDepth = function (node) {
  if (node === null) return 0;
  if (node.left === null) return minDepth(node.right) + 1
  if (node.right === null) return minDepth(node.left) + 1
  return Math.min(minDepth(node.left), minDepth(node.right)) + 1;
};
```
