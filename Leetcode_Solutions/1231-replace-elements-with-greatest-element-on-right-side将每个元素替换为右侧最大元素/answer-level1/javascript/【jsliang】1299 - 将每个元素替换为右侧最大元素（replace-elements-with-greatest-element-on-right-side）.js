仔细思考了这道题，一开始想了个笨法子（太笨就不展示了），觉得可能会超时。

于是琢磨了下：

> 暴力破解

```js
const replaceElements = (arr) => {
  const newArr = [...arr].sort((a, b) => b - a);
  for (let i = 0; i < arr.length; i++) {
    const index = newArr.indexOf(arr[i]);
    newArr.splice(index, 1);
    arr[i] = newArr[0];
  }
  arr[arr.length - 1] = -1;
  return arr;
};
```

我们执行了以下步骤：

1. 先对 `newArr` 进行 `arr` 的从大到小倒序排序。
2. 遍历 `arr`，先查找 `newArr` 中 `arr[i]` 这个元素并删除。
3. 设置 `arr[i]` 为当前数组最大的元素（即 `arr[0]`）。
4. 最后特意设置最后一个元素为 `-1`，返回 `arr` 即可。

Submit 提交：

```js
Accepted
* 15/15 cases passed (316 ms)
* Your runtime beats 32.42 % of javascript submissions
* Your memory usage beats 27.85 % of javascript submissions (41.1 MB)
```

官方总能让我意想不到：

> 逆序遍历

```js
const replaceElements = (arr) => {
  const result = Array.from(Array(arr.length), () => '');
  result[result.length - 1] = -1;
  for (let i = arr.length - 2; i >= 0; i--) {
    result[i] = Math.max(result[i + 1], arr[i + 1]);
  }
  return result;
};
```

因为最后输出的数组是倒序的，所以我们通过倒序比较 `arr` 即可。

> 说，你的天地一号哪里买的！

Submit 提交：

```js
Accepted
* 15/15 cases passed (100 ms)
* Your runtime beats 68.49 % of javascript submissions
* Your memory usage beats 31.65 % of javascript submissions (40.3 MB)
```

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library