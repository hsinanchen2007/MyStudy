
```
const getMaxDepth = (node) => {
  if(!node) return 0
  if(!node.children.length) return 1
  return Math.max(...node.children.map(n => {
    const v = getMaxDepth(n)
    return v ? v + 1: 0
  }))
}

var maxDepth = function(root) {
    return getMaxDepth(root)
};
```
