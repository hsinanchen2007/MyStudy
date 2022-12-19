```javascript []
var zigzagLevelOrder = function(root, level = 0, arr = [], way = true) {
  if (!root) return arr;
  zigzagLevelOrder(root.left, level + 1, arr, !way);
  if (arr[level]) {
    if (way) arr[level].push(root.val);
    else arr[level].unshift(root.val);
  } else arr[level] = [root.val];
  zigzagLevelOrde(root.right, level + 1, arr, !way);
  return arr;
};
```
# 解题思路
使用正常的DFS，同时维护一个布尔值` way `，控制插入新元素的位置