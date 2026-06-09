> 递归

```js
const findSecondMinimumValue = (root) => {
  const result = [];
  const ergodic = (root) => {
    if (!root) {
      return;
    }
    result.push(root.val);
    ergodic(root.left);
    ergodic(root.right);
  }
  ergodic(root);
  return [...new Set(result)][1] || -1;
};
```

> 迭代

```js
const findSecondMinimumValue = (root) => {
  const newRoot = [root];
  const result = [];
  while (newRoot.length) {
    const tempRoot = newRoot.pop();
    result.push(tempRoot.val)
    if (tempRoot.left) {
      newRoot.push(tempRoot.left);
    }
    if (tempRoot.right) {
      newRoot.push(tempRoot.right);
    }
  }
  return [...new Set(result.sort((a, b) => a - b))][1] || -1;;
};
```

详解欢迎到 [jsliang 的文档库 - LeetCode](https://github.com/LiangJunrong/document-library/tree/master/other-library/LeetCode) 吐槽~
