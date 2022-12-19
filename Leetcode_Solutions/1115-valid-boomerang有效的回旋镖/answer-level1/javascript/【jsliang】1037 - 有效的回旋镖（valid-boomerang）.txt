元芳，这道题你怎么看？

大人！我不知道这道题数学公式！

是的，坑爹的，又要百度搜索公式了：

* 判断三个点是否构成三角形公式：(Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By)) / 2 !== 0

> 暴力破解

```js
const isBoomerang = (points) => {
  const Ax = points[0][0];
  const Ay = points[0][1];
  const Bx = points[1][0];
  const By = points[1][1];
  const Cx = points[2][0];
  const Cy = points[2][1];
  return (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By)) / 2 !== 0;
};
```

直接套用公式就行了，Submit 提交：

```js
Accepted
* 190/190 cases passed (60 ms)
* Your runtime beats 93.1 % of javascript submissions
* Your memory usage beats 38.78 % of javascript submissions (33.8 MB)
```

那些说只需要一行的给我站住，看我不兜晕你：

> 一行求解

```js
const isBoomerang = (points) => (points[0][0] * (points[1][1] - points[2][1]) + points[1][0] * (points[2][1] - points[0][1]) + points[2][0] * (points[0][1] - points[1][1])) / 2 !== 0;
```

Submit 提交：

```js
Accepted
* 190/190 cases passed (64 ms)
* Your runtime beats 77.59 % of javascript submissions
* Your memory usage beats 97.96 % of javascript submissions (33.5 MB)
```

## <a name="chapter-six" id="chapter-six"></a>六 进一步思考

> [返回目录](#chapter-one)

肯定还有的小伙伴说会有更简单的公式：

> 暴力破解【简化】

```js
/**
 * @name 有效的回旋镖
 * @param {number[][]} points
 * @return {boolean}
 */
const isBoomerang = (points) => {
  const dx = points[1][0] - points[0][0];
  const dy = points[1][1] - points[0][1];
  const ex = points[2][0] - points[0][0];
  const ey = points[2][1] - points[0][1];
  return dx * ey != ex * dy;
}
```

Submit 提交：

```js
Accepted
* 190/190 cases passed (60 ms)
* Your runtime beats 93.1 % of javascript submissions
* Your memory usage beats 97.96 % of javascript submissions (33.5 MB)
```

就酱，这道题就结束啦！

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library