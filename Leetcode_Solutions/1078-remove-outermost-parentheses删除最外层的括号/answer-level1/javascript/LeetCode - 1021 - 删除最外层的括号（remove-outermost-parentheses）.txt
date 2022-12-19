鲁迅曾经说过：

* 括号太多看不过来

讲真看得我有点眼花，我都要凑过去数括号了（近视加深 ing……）

吐槽完毕，开始解题：

1. 存在一个有效的括号：`(()())(())`。
2. 首先我们需要对其原语化。什么是原语化？即对这个有效括号进行拆分，拆分出来的括号还是有效的：`(()())` + `(())`。这时候，我们不能进一步拆分了，这样的操作就叫做原语化。
3. 然后我们去掉原语化后每个块的外层括号，变成：`()()` + `()`。
4. 所以得到答案：`()()()`。

这样，答案呼之欲出：

> 暴力破解

```js
const removeOuterParentheses = (S) => {
  // 1. 设置数组获取原语
  const primitive = [];

  // 2. 初始化堆栈
  let now = [S[0]];

  // 3. 设置游标
  let flag = 0;

  // 4. 遍历函数
  for (let i = 1; i < S.length; i++) {
    // 4.1 如果当前的括号和栈顶元素一致，则添加，否则则推出
    if (S[i] === now[now.length - 1]) {
      now.push(S[i]);
    } else {
      now.pop();
    }
    // 4.2 如果 now 没长度了，说明当前是一个有效的括号了，进行一系列操作
    if (!now.length) {
      primitive.push(S.slice(flag, i + 1));
      flag = i + 1;
      now = [S[i + 1]];
      i++;
    }
  }

  // 5. 遍历原语，进行操作
  for (let i = 0; i < primitive.length; i++) {
    primitive[i] = primitive[i].slice(1, primitive[i].length - 1);
  }

  // 6. 将原语换成字符串
  return primitive.join('');
};
```

Submit 提交：

```js
Accepted
* 59/59 cases passed (84 ms)
* Your runtime beats 19.7 % of javascript submissions
* Your memory usage beats 10.44 % of javascript submissions (37.5 MB)
```

这是 **jsliang** 一开始的思路，也是最暴躁的思路，毕竟刚出社会的小伙伴不怕刚，直到社会磨平了他的棱角：

> 暴力破解【优化】

```js
const removeOuterParentheses = (S) => {
  const primitive = []; // 原语化数组
  let nowPrimitive = [S[0]]; // 当前原语
  const now = [S[0]]; // 当前堆栈
  for (let i = 1; i < S.length; i++) {
    // 堆栈操作
    if (S[i] === now[now.length - 1]) {
      now.push(S[i]);
    } else {
      now.pop();
    }
    // 原语操作
    nowPrimitive.push(S[i]);
    if (!now.length) {
      now.push(S[i + 1]);
      i++;

      nowPrimitive.shift();
      nowPrimitive.pop();
      primitive.push(nowPrimitive.join(''));
      nowPrimitive = [S[i + 1]];
    }
  }
  return primitive.join('');
};
```

Submit 提交：

```js
Accepted
* 59/59 cases passed (76 ms)
* Your runtime beats 40.66 % of javascript submissions
* Your memory usage beats 16.13 % of javascript submissions (37.1 MB)
```

接下来就是看看大佬操作了：

* https://leetcode-cn.com/problems/remove-outermost-parentheses/solution/javascript-jian-dan-de-deltafa-bu-xu-yao-stack-by-/

> delta 法

```js
const removeOuterParentheses = (S) => {
  let delta = 0;
  let res = '';

  for (const ch of S) {
    if (ch === '(' && delta !== 0 || ch === ')' && delta !== 1) {
      res += ch;
    }
    if (ch === '(') {
      ++delta;
    } else if (ch === ')') {
      --delta;
    }
  }

  return res;
};
```

Submit 提交：

```js
Accepted
* 59/59 cases passed (68 ms)
* Your runtime beats 78.28 % of javascript submissions
* Your memory usage beats 46.52 % of javascript submissions (36.2 MB)
```

至于这操作怎么理解，我也是第一次看啊~

你品，你细细地品~

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library