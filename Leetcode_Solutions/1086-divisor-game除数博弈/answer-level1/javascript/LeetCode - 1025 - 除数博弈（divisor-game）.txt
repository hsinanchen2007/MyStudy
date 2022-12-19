我感觉这是一道找规律题啊，先摸清敌情：

```
【√】2 -> 1
【X】3
【√】4 -> 1
【X】5
【√】6 -> 1
【X】7
【√】8 -> 1
【x】9
【√】10 -> 1
【X】11
【X】12 -> 1
【X】13
【√】14 -> 1
【X】15

不行：3 5 7 9 11 13 15
```

enm...判断奇偶数？这么简单？！

> 暴力破解

```js
const divisorGame = (N) => {
  return N % 2 === 0;
};
```

Submit 提交：

```js
Accepted
* 40/40 cases passed (64 ms)
* Your runtime beats 62.69 % of javascript submissions
* Your memory usage beats 83.73 % of javascript submissions (33.7 MB)
```

enm......

真没啥花里胡哨的~

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：本题太简单不贴了

GitHub：本题太简单真不贴了