是的，你没看错，就是【泰】波波那契数，一开始我还以为是斐波那契数列，想了老久这应该是自定义数列？

> 百度没有搜索到这种数列

那么，开始解题：

> 暴力破解【超时】

```js
const tribonacci = (n) => {
  if (n === 0) {
    return 0;
  } else if (n === 1) {
    return 1
  } else if (n === 2) {
    return 1
  } else {
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
  }
};
```

惯用思路就是递归啦，然而这有点不好的就是它会超时。

Submit 提交：

```js
Time Limit Exceeded
* 36/39 cases passed (N/A)

Testcase
* 35
```

想当年搞斐波那契数列，见过一种粗暴方法：

> 超暴力破解

```js
const tribonacci = (n) => [0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, 121415, 223317, 410744, 755476, 1389537, 2555757, 4700770, 8646064, 15902591, 29249425, 53798080, 98950096, 181997601, 334745777, 615693474, 1132436852, 2082876103][n];
```

Submit 提交：

```js
Accepted
* 39/39 cases passed (60 ms)
* Your runtime beats 75.69 % of javascript submissions
* Your memory usage beats 38.46 % of javascript submissions (33.8 MB)
```

好了，这种测试用例编程仅能玩玩，咱们还是考虑下优化下递归~

> 递归 + 哈希表

```js
const tribonacci = (n) => {
  // 1. 设置 list 记录表
  const list = [];
  // 2. 设置 ergidic 进行递归
  const ergodic = (n) => {
    // 3. 如果有这个内容，直接返回
    if (list[n]) {
      return list[n];
    }
    // 4. 如果没有，就进行正常操作
    if (n === 0) {
      return 0;
    } else if (n === 1) {
      return 1;
    } else if (n === 2) {
      return 1;
    } else {
      const num = ergodic(n - 3) + ergodic(n - 2) + ergodic(n  - 1);
      // 4.1 特别注意，进行 list 添加
      list[n] = num;
      return num;
    }
  }
  // 5. 返回结果
  return ergodic(n);
};
```

如上，我们将一开始超时的递归方法，进行优化，添加个 `list` 记录列表即可。

Submit 提交：

```js
Accepted
* 39/39 cases passed (76 ms)
* Your runtime beats 10.07 % of javascript submissions
* Your memory usage beats 88.94 % of javascript submissions (33.6 MB)
```

那么接下来去瞅瞅大佬操作了~

> 【题解区】自底向上

```js
const tribonacci = (n) => {
  if (n === 0) {
    return 0;
  } else if (n === 1) {
    return 1;
  } else if (n === 2) {
    return 1;
  }
  let a = 0, b = 1, c = 1;
  for (let i = 3; i <= n; i++) {
    const temp = a + b + c;
    a = b;
    b = c;
    c = temp;
  }
  return c;
};
```

Submit 提交：

```js
Accepted
* 39/39 cases passed (60 ms)
* Your runtime beats 75.69 % of javascript submissions
* Your memory usage beats 94.23 % of javascript submissions (33.6 MB)
```

非常 nice 的想法啦，通过一次循环逐个添加即可。

当然，如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library