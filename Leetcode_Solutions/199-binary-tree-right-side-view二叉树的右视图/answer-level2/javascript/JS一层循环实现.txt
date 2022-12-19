一般层序迭代遍历都是两层循环实现, 我这也算提供不一样的思路吧......

```js
var rightSideView = function(root) {
  if (!root) return [];

  // 生成层标记, 添加在每层末尾
  const SEPARATOR = Symbol();

  const queue = [root, SEPARATOR];

  const res = [];
  let lastNode = null;

  while (queue.length) {
    const node = queue.shift();

    if (node === SEPARATOR) {
      if (lastNode) {
        res.push(lastNode.val);
        lastNode = null;
        queue.push(SEPARATOR);
      }

      continue;
    }

    if (node.left) queue.push(node.left);
    if (node.right) queue.push(node.right);

    lastNode = node;
  }

  return res;
};
```