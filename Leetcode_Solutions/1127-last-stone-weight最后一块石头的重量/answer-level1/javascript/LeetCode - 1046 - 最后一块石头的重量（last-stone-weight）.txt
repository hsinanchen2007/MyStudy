LeetCode 越来越过分了：

1. 第 1000 题之后，官方题解基本不写。
2. 第 1042 题的 图（Tag），让我搞了 3 个多钟。
3. 到了第 1046 这道题，连示例都不写了。
4. ……

LeetCode 你变了~

重构题目：

---
参数：

* stones：[2, 3, 3]。有一堆石头，它的范围是 [1, 30]，并且里面每个值大小是 [1, 1000]。

内容：

1. 每次遍历，先挑选两块最重的石头 x 和 y（数字最大的前两块），x <= y，让它们进行互相碾压。
2. 如果两块石头重量一样，那么它们都变成了渣渣，消失于 `stones` 中。
3. 如果这两块石头重量不一样，那么较大的那块会剩下 `y - x` 的渣渣，然后这个渣渣重新加入 `stones` 大家庭中。
4. 碾压到剩下一块石头为止，胜者为王！返回它的重量！
---

OK，咱们开始拿几个例子看看：

> 示例 1

```
输入：[2, 3, 3]
输出：2
解释：3 和 3 同归于尽，剩下 2
```

> 示例 2

```
输入：[2, 3, 4]
输出：1
解释：4 和 3 互相碾压变成 1，2 和 1 互相碾压剩下 1
```

这样，我们就可以得出答案：

> 暴力破解

```js
const lastStoneWeight = (stones) => {
  stones.sort((a, b) => a - b);
  while (stones.length > 1) {
    const one = stones.pop();
    const two = stones.pop();
    if (one - two !== 0) {
      stones.push(one - two);
      stones.sort((a, b) => a - b);
    }
  }
  return stones[0] || 0;
};
```

Submit 提交：

```js
Accepted
* 70/70 cases passed (68 ms)
* Your runtime beats 78.24 % of javascript submissions
* Your memory usage beats 83.33 % of javascript submissions (34.6 MB)
```

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library