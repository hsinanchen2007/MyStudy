这个 Tag 打了个 **脑经急转弯**，我是有点措手不及，好像 200 多道题来第一次看到~

而且，坑爹的是它有个 `3 5 1`，提交之后我才发现并不是 `[x, y, z] = [a, b, c]`，而是给出 `a, b, c` 三个数你，你需要先自行排序！

> 脑筋急转弯

```js
const numMovesStones = (a, b, c) => {
  const sort = [a, b, c].sort((a, b) => a - b);
  [a, b, c] = [sort[0], sort[1], sort[2]];
  // 1. 开场天胡
  if (a + 1 === b && b + 1 === c) {
    return [0, 0];
  } else if (b - a <= 2 || c - b <= 2) { // 2. 挪动 1 个仔即可
    return [1, c - a - 2];
  } else { // 3. 需要挪动 2 个仔
    return [2, c - a - 2];
  }
};
```

OK，咱们聊聊做法：

1. 开场天胡的咱们就不多说了，一步都挪不动：`[1, 2, 3]`。这种情况是 `a + 1 = b, b + 1 = c`。
2. 开场地胡的咱们至少可以移动一次，就是：`[1, 3, 4]`。这种情况是 `b - a <= 2, c - b <= 2`。
3. 开场啥都不胡（非酋你好）的咱们辛苦下，至少移动两次，类似：`[1, 5, 8]`。这种情况就排除其他两种情况即可。
4. 那么最多移动多少次？以 `b` 为固定点，结果是：`(b - a - 1) + (c - b - 1)`，所以就是 `c - a - 2` 了。

Submit 提交：

```js
Accepted
* 187/187 cases passed (64 ms)
* Your runtime beats 81.54 % of javascript submissions
* Your memory usage beats 71.19 % of javascript submissions (33.7 MB)
```

OK，搞定完事~

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library