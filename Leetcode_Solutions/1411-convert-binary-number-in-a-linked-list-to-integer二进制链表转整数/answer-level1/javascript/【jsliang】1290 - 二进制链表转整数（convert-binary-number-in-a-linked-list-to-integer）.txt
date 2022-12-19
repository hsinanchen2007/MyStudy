要记住的是，渣渣 **jsliang** 对于树和链表只有两种法子：

1. 递归
2. 迭代

咱们先上迭代：

> 迭代

```js
const getDecimalValue = (head) => {
  const newHead = [head];
  let binary = '';
  while (newHead.length) {
    const tempHead = newHead.pop();
    binary += tempHead.val;
    if (tempHead.next) {
      newHead.push(tempHead.next);
    }
  }
  return parseInt(binary, 2);
};
```

迭代的法子就是：

1. 将链表放进数组。
2. 每次都将最外面的元素推出来。
3. 通过 `binary` 累加结果值。
4. 再将链表的 `next` 节点推进数组。

Submit 提交：

```js
Accepted
* 102/102 cases passed (56 ms)
* Your runtime beats 94.62 % of javascript submissions
* Your memory usage beats 52.82 % of javascript submissions (33.8 MB)
```

当然，因为这道题还是有优化空间的，所以咱么可以进一步优化：

> 迭代【优化】

```js
const getDecimalValue = (head) => {
  let binary = '';
  while (head) {
    binary += head.val;
    head = head.next;
  }
  return parseInt(binary, 2);
};
```

Submit 提交：

```js
Accepted
* 102/102 cases passed (56 ms)
* Your runtime beats 94.62 % of javascript submissions
* Your memory usage beats 83.06 % of javascript submissions (33.7 MB)
```

迭代讲完了，咱们玩玩递归。

> 递归

```js
const getDecimalValue = (head) => {
  let binary = '';
  const ergodic = (head) => {
    if (!head) {
      return;
    }
    binary += head.val;
    ergodic(head.next);
  }
  ergodic(head);
  return parseInt(binary, 2);
};
```

递归的法子就是：

1. 设置递归函数 `ergodic`。
2. 如果深入到最终的节点为 `null`，那么中止递归。
3. 通过 `binary` 累加二进制值。
4. 重复 `ergodic(head.next)` 直到碰到 `!head` 为止。

Submit 提交：

```js
Accepted
* 102/102 cases passed (64 ms)
* Your runtime beats 70.17 % of javascript submissions
* Your memory usage beats 68.55 % of javascript submissions (33.7 MB)
```

当然，递归也有优化法子：

> 递归【优化】

```js
const getDecimalValue = (head, binary = '') => {
  if (!head) {
    return parseInt(binary, 2);
  }
  binary += head.val;
  return getDecimalValue(head.next, binary);
};
```

Submit 提交：

```js
Accepted
* 102/102 cases passed (60 ms)
* Your runtime beats 88.75 % of javascript submissions
* Your memory usage beats 68.55 % of javascript submissions (33.7 MB)
```

好了，今天的题目就到这里。

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library