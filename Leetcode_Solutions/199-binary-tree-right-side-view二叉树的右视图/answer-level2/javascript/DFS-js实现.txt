从右子树开始进行DFS递归遍历
保留第一次遍历到的值
```js
var rightSideView = function(root, depth = 0, res = []) {
  if(!root) return []
  if(!res[depth]) {
    res[depth] = root.val
  }
  rightSideView(root.right, depth + 1, res)
  rightSideView(root.left, depth + 1, res)
  return res
};
```
