说难不难，说简单也简单（就是很简单）。

观察题目，注意以下几点：

1. 只能按照 `points` 顺序前行。
2. 只能按 米 字状一次移动一个。

已知有数组：`[[1, 1], [3, 4], [-1, 0]]`

那么，我们从 `[1, 1] => [3, 4]` 需要多久时间呢？

答案：4 - 1 = 3

那么，我们从 `[3, 4] => [-1, 0]` 需要多久时间呢？

答案：4 - 0 = 4 或者 3 - -1 = 4

小心求证大胆假设，按照这样的说法，我们是不是应该有公式：

* Math.max( | y2 - y1 |, | x2 - x1 |)

其中 || 为求绝对值，毕竟时间为正的。

所以，咱们小心求证试试：

> 找规律

```js
const minTimeToVisitAllPoints = (points) => {
  let result = 0;
  for (let i = 0; i < points.length - 1; i++) {
    result += Math.max(Math.abs(points[i + 1][0] - points[i][0]), Math.abs(points[i + 1][1] - points[i][1]));
  }
  return result;
};
```

Submit 提交：

```js
Accepted
* 122/122 cases passed (72 ms)
* Your runtime beats 54.19 % of javascript submissions
* Your memory usage beats 84.66 % of javascript submissions (34.7 MB)
```

OK，搞定完事~

为了方便好看点，**jsliang** 优化下：

> 找规律【优化】

```js
const minTimeToVisitAllPoints = (points) => {
  let result = 0;
  for (let i = 0; i < points.length - 1; i++) {
    const x1 = points[i][0];
    const y1 = points[i][1];
    const x2 = points[i + 1][0];
    const y2 = points[i + 1][1];
    result += Math.max(Math.abs(x2 - x1), Math.abs(y2 - y1));
  }
  return result;
};
```

Submit 提交：

```js
Accepted
* 122/122 cases passed (64 ms)
* Your runtime beats 88.37 % of javascript submissions
* Your memory usage beats 80.83 % of javascript submissions (34.7 MB)
```

OK，如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library