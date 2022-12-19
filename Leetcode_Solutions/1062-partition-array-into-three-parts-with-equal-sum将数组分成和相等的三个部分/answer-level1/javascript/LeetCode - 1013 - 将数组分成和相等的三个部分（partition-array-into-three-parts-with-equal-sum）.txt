> 好像 1000 题后的简单题 LeetCode 都不给官方题解了？

按照题目的意思，就是我们需要三等分一个数组。

假设数组类似于一根棒子，我们需要拿刀将其切成三等分，如果能成，返回 `true`，如果不成，返回 `false`。

例如数组：`[1, 7, 2, 6, 3, 5]`，我们可以切成：`[1, 7], [2, 6], [3, 5]`，这样就是 3 等分了。

所以我们需要考虑着两个点落在哪，才能获取三等分：

> 暴力破解【超时】

```js
const canThreePartsEqualSum = (A) => {
  // 减少一次 reduce 操作
  const sum = A.reduce((prev, next) => prev + next);
  for (let i = 0; i < A.length - 2; i++) {
    for (let j = i + 1; j < A.length - 1; j++) {
      const sum1 = A.slice(0, i + 1).reduce((prev, next) => prev + next);
      const sum2 = A.slice(i + 1, j + 1).reduce((prev, next) => prev + next);
      const sum3 = sum - sum1 - sum2;
      if (sum1 === sum2 && sum1 === sum3) {
        return true;
      }
    }
  }
  return false;
};
```

这时候给出的 Submit 提交为：

```js
Time Limit Exceeded
* 48/53 cases passed (N/A)
```

暴力有风险，使用需谨慎~

那么我们换个思路：

* 获取每份的长度 `one`，当竹竿累计到 `one` 的长度的时候，我们就砍掉它，同时 `time++`，判断最后是不是出现了 3 次即可。

> 暴力破解【通过】

```js
const canThreePartsEqualSum = (A) => {
  // 1.计算 3 等分中每份的总额
  const one = A.reduce((prev, next) => prev + next) / 3;
  
  // 2. 设置 tempSum 表示目前累计，设置 time 表示目前能构成三等分的次数
  let tempSum = 0;
  let time = 0;

  // 3. 遍历计数
  for (let i = 0; i < A.length; i++) {
    tempSum += A[i];
    if (tempSum === one) {
      time++;
      tempSum = 0;
    }
  }

  // 4. 判断总次数是否为 3 次
  return time === 3;
};
```

Submit 提交：

```js
Accepted
* 53/53 cases passed (76 ms)
* Your runtime beats 81.25 % of javascript submissions
* Your memory usage beats 83.72 % of javascript submissions (39.6 MB)
```

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library