不要被题意迷惑，咱们不管是顺着走还是逆着走最近，地球是圆的，咱们先把顺着走的计算出来：

> 暴力破解

```js
const distanceBetweenBusStops = (distance, start, destination) => {
  const newStart = Math.min(start, destination);
  const newDestination = Math.max(start, destination);
  let dis = 0;
  let order = 0;
  for (let i = 0; i < distance.length; i++) {
    dis += distance[i];
    if (i >= newStart && i < newDestination) {
      order += distance[i];
    }
  }
  return Math.min(order, dis - order);
};
```

第一步先对齐 `start` 和 `destination`，变成 `newStart` 和 `newDestination`，让他两顺着排序。

第二步设置总长度 `dis`。

第三步设置顺着走长度 `order`。

题目的意思是给个数组 `distance = [1, 2, 3, 4]`，然后：

1. 第 0 个元素就是：0 -> 1 的距离。
2. 第二个元素是 `1 -> 2` 的距离。
3. ……所以咱们需要求 `newStart` 到 `newDestination` 的距离，那么就是 `[newStart, newDestination)` 的距离啦，注意开闭区间。

第四步就直接返回 `order` 和 `dis - order` 的最小值即可~

Submit 提交：

```js
Accepted
* 37/37 cases passed (68 ms)
* Your runtime beats 47.71 % of javascript submissions
* Your memory usage beats 19.15 % of javascript submissions (34.7 MB)
```

当然，如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~
