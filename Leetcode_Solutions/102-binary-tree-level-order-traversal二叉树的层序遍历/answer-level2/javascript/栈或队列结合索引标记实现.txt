```js
var levelOrder = function(root) {
    const res = [];
    const stack = [{ index: 0, node: root }];

    while (stack.length > 0) {
        const { index, node } = stack.pop();

        if (!node) continue;

        res[index] = res[index] ? [...res[index], node.val] : [node.val];

        stack.push({ index: index + 1, node: node.right });
        stack.push({ index: index + 1, node: node.left });
    }

    return res;
};
```

对比一下队列实现

```js
var levelOrder = function(root) {
    const res = [];
    const queue = [{ index: 0, node: root }];

    while (queue.length > 0) {
        const { index, node } = queue.shift();

        if (!node) continue;

        res[index] = res[index] ? [...res[index], node.val] : [node.val];

        queue.push({ index: index + 1, node: node.left });
        queue.push({ index: index + 1, node: node.right });
    }

    return res;
};
```

不用标记的迭代实现:

```js
var levelOrder = function(root) {
    const res = [];
    let queue = [root];

    while (queue.length > 0) {
        const level = [];

        queue = queue.reduce((acc, current) => {
            if (!current) return acc;

            level.push(current.val);

            acc.push(current.left);
            acc.push(current.right);

            return acc;
        }, []);

        if (level.length > 0) res.push(level);
    }

    return res;
};
```