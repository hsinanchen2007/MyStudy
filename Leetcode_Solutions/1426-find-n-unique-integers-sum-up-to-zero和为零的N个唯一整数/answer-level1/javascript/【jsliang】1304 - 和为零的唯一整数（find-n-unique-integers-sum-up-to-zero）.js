这道题给了 **jsliang** 最大程度的自由，所以可以随心所欲，任性发挥：

> 暴力破解

```js
const sumZero = (n) => {
  // 1. 定义变量
  let number = n,
      flag = false;
  
  // 2. 定义结果值
  const result = [];
  for (let i = 0; i < n; i++) {
    // 2.1 判断是输入正数还是负数
    if (flag) {
      result.push(-number);
      number--;
      flag = false;
    } else {
      result.push(number);
      flag = true;
    }
  }

  // 3. 判断是否为奇数长度位
  if (result.length % 2 === 1) {
    result[result.length - 1] = 0;
  }

  // 4. 输出结果
  return result;
};
```

是的，正如上面所写，如果 `n` 为 5，那么输出：

* [5, -5, 4, -4, 0]

如果 `n` 为 4，那么输出：

* [4, -4, 3, -3]

Submit 提交：

```js
Accepted
* 42/42 cases passed (64 ms)
* Your runtime beats 87.12 % of javascript submissions
* Your memory usage beats 83.1 % of javascript submissions (34.9 MB)
```

那么本题题解就到这里。

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library