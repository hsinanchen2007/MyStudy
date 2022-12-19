```javascript []
var sufficientSubset = function (root, limit) {
  if (!root.left && !root.right) return limit - root.val > 0 ? null : root;
  root.left && (root.left = sufficientSubset(root.left, limit - root.val))
  root.right && (root.right = sufficientSubset(root.right, limit - root.val))
  return !root.left && !root.right ? null : root
};
```
