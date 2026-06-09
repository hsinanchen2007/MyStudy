题目很简洁，稍微理解下应该能分析到题意：

```
示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]

示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]
```

意思即是：

1. 统计在每个字段中都出现的字符；
2. 如果出现多次，则显示多次。

简单来说：

* 开心消消乐

那么，开始游戏：

> 暴力破解

```js
const commonChars = (A) => {
  return A.map(item => item.split('')).reduce((prev, next) => {
    return prev.filter(item => {
      const index = next.indexOf(item);
      if (index > -1) {
        next.splice(index, 1);
        return true;
      }
      return false;
    });
  });
};
```

1. 通过 `A.map()` 返回一个新数组，将 A 里面所有字符串元素转换成数组。
2. 通过 `A.map().reduce()` 进行累加操作，这个累加，是通过前后的对比进行合计。例如有 `['bella', 'label', 'roller']`，那么第一次是 `bella` 和 `label` 进行比对，留下 `b, e, l, l, a`；第二次是 `b, e, l, l, a` 和 `roller` 比对，留下 `e, l, l`。
3. 通过 `prev.filter()` 过滤它和 `next` 中相同的每一项。本来打算用 `has` 直接过滤取交集的，发现它不能过滤重复出现的元素，只要手动操作了。

Submit 提交：

```js
Accepted
* 83/83 cases passed (72 ms)
* Your runtime beats 92.73 % of javascript submissions
* Your memory usage beats 63.05 % of javascript submissions (37.4 MB)
```

还是挺不错的~

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library