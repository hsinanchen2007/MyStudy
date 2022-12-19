DFS:
```javascript
var maxDepth = function(root) {
  if (!root) return 0;
  return Math.max(
    maxDepth(root.left),
    maxDepth(root.right)
  ) + 1;
};
```

BFS:
```javascript
var maxDepth = function(root) {
  if (!root) return 0;
  let queue = [ root ];
  let depth = 1;
  while(true) {
    const temp = [];
    for (let item of queue) {
      if (item.left) temp.push(item.left);
      if (item.right) temp.push(item.right);
    }
    if (temp.length) {
      depth++;
      queue = temp;
    } else {
      return depth;
    }
  }
};
```