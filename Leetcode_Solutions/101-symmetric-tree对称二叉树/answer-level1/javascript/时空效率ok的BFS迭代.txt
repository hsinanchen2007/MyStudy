```js
var isSymmetric = function(root) {
  if (!root) return true;

  const queue = [root.left, root.right];

  let splitIndex = 1;

  while (queue.length > 0) {
    const size = queue.length;

    const leftPart = queue.slice(0, splitIndex);
    const rightPart = queue.slice(splitIndex, queue.length);

    if (leftPart.length !== rightPart.length) return false;

    for (let i = 0; i < leftPart.length; i++) {
      const left = leftPart[i];
      const right = rightPart[size - i - 1 - leftPart.length];

      // REVIEW: 操作对象前需要先转成 boolean
      if (!left ^ !right) return false;

      if (left && right) if (left.val !== right.val) return false;
    }

    for (let i = 0; i < size; i++) {
      const node = queue.shift();

      if (!node) continue;

      queue.push(node.left);
      queue.push(node.right);
    }

    splitIndex = queue.length / 2;
  }

  return true;
};
```