```
var levelOrder = function(root) {
  if(!root) return []
  let res = []
  const dfs = (node, level) => {
    if(node) {
      if(!res[level]) {
        res[level] = [node.val]
      } else {
        res[level].push(node.val)
      }
      dfs(node.left, level + 1)
      dfs(node.right, level + 1)
    }
  }

  dfs(root, 0)
  return res
};
```
