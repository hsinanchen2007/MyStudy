- 通过上一层的节点来left和right来保存下一次的节点
```
var maxLevelSum = function (root) {
  let queue = [root];
  let max = root.val;
  let res = 1;
  let depth = 1;
  while (queue.length) {
    let temp = [];
    let val = 0;
    ++depth;
    queue.forEach(node => {
      if (node.left) {
        temp.push(node.left)
        val += node.left.val
      }
      if (node.right) {
        temp.push(node.right)
        val += node.right.val
      }
    })
    queue = temp;
    if (val > max) {
      max = val;
      res = depth;
    }
  }
  return res;
};
```
