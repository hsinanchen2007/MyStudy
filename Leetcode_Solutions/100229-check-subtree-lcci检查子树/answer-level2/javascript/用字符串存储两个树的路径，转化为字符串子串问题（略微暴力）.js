
### 思路

1. 获取两棵树的路径path1和path2
2. 判断path2是否为path1的子串


代码非常简单，缺点就是需要遍历两棵完整树(有点没底线--)，时间复杂度较大

### 代码

```js
var checkSubTree = function(t1, t2) {
  return dfs(t1).indexOf(dfs(t2)) > -1;
  function dfs(node) {
    if(!node) return '';
    return node.val + dfs(node.left) + dfs(node.right);
  }
};
```
