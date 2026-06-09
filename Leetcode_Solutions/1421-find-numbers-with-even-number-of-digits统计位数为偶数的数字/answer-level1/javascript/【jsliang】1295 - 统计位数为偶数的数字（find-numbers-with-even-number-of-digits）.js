如果要秀的话，那就是一行求解：

> 一行求解

```js
const findNumbers = (nums) => nums.reduce((prev, next) => prev + (String(next).length % 2 === 0 ? 1 : 0), 0);
```

Submit 提交：

```js
Accepted
* 102/102 cases passed (76 ms)
* Your runtime beats 22.77 % of javascript submissions
* Your memory usage beats 85.34 % of javascript submissions (35.2 MB)
```

如果小伙伴想看清楚的话，那就转成多行：

> 暴力破解

```js
const findNumbers = (nums) => {
  let time = 0;
  for (let i = 0; i < nums.length; i++) {
    if (String(nums[i]).length % 2 === 0) {
      time++;
    }
  }
  return time;
};
```

Submit 提交：

```js
Accepted
* 102/102 cases passed (68 ms)
* Your runtime beats 67.89 % of javascript submissions
* Your memory usage beats 87.97 % of javascript submissions (35.2 MB)
```

当然，也许还有其他法子，但是我觉得杀鸡焉用牛刀，两种就够用了~

如果小伙伴还有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library