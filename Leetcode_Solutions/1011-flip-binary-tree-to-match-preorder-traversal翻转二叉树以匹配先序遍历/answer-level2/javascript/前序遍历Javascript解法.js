思路: 前序遍历，同时用cur指向voyage数组，遍历访问的时候判断数字是否对的上，对不上尝试左右调换。最后判断cur是否走到最后就好了。
```javascript
var flipMatchVoyage = function(root, voyage) {
  let ans = [];
  let cur = 0;
  function dfs(tree) {
    if (tree.val === voyage[cur]) {
      cur++;
      if (tree.left && tree.left.val === voyage[cur]) {
        dfs(tree.left);
      }
      if (tree.right && tree.right.val === voyage[cur]) {
        dfs(tree.right);
        if (tree.left && tree.left.val === voyage[cur] && tree.left) {
          ans.push(tree.val);
          dfs(tree.left);
        }
      }
    }
  }
  dfs(root);
  if (cur !== voyage.length) {
    return [-1];
  }
  return ans;
};

```
