题目的意思很简单：

1. 给定一个数组 `dominoes`。
2. 假设其里面的值为 `[[1, 2], [2, 1], [1, 2], [1, 3]]`。
3. 那么 `[1, 2]` 和 `[2, 1]` 能构成多米诺骨牌，`[1, 2]`（第 1 个元素） 和 `[1, 2]`（第 3 个元素）也能构成多米诺骨牌。
4. 返回数组中能构成多米诺骨牌的对数。

那么 **jsliang** 表示有个疑问：`[[1, 2], [2, 1], [1, 2]]` 是不是能构成 3 对，还是说一个元素只能使用一次。

所以，尝试破解吧：

> 暴力破解

```js
const numEquivDominoPairs = (dominoes) => {
  let result = 0;
  for (let i = 0; i < dominoes.length - 1; i++) {
    for (let j = i + 1; j < dominoes.length; j++) {
      if (
        (dominoes[i][0] === dominoes[j][0]
          && dominoes[i][1] === dominoes[j][1])
        ||
        (dominoes[i][0] === dominoes[j][1]
          && dominoes[i][1] === dominoes[j][0])
      ) {
        result++;
      }
    }
  }
  return result;
};
```

完全按照题目意思做即可。

Submit 提交：

```js
Accepted
* 19/19 cases passed (4596 ms)
* Your runtime beats 9.86 % of javascript submissions
* Your memory usage beats 93.22 % of javascript submissions (40.7 MB)
```

那么，有没有法子优化呢？

咱们先观察下：

* 如果仅有一个时，不构成多米诺骨牌，所以为 0。
* 如果有两个时，构成 1 对。
* 如果有三个时，构成 3 对。
* ……
* 如果有 n 个时，构成 n(n - 1)/2 对。

表示为：

```
1 -> 0
2 -> 1
3 -> 3
4 -> 6
5 -> 10
6 -> 15
... -> ...
n -> n(n - 1)/2
```

OK，那这样就简单啦，可以利用下哈希表：

> 哈希表

```js
const numEquivDominoPairs = (dominoes) => {
  let result = 0;
  const map = new Map();
  for (let i = 0; i < dominoes.length; i++) {
    const now = `${Math.min(dominoes[i][0], dominoes[i][1])}${Math.max(dominoes[i][0], dominoes[i][1])}`;
    if (map.has(now)) {
      const time = map.get(now);
      result += time;
      map.set(now, map.get(now) + 1);
    } else {
      map.set(now, 1);
    }
  }
  return result;
};
```

Submit 提交：

```js
Accepted
* 19/19 cases passed (76 ms)
* Your runtime beats 95.77 % of javascript submissions
* Your memory usage beats 59.32 % of javascript submissions (42.4 MB)
```

OK，又破解了一道题，嗨皮~

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library