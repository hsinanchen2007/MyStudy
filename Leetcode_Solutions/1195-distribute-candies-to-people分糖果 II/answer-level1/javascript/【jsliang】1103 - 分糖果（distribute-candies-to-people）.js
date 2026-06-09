挺喜欢这种新奇的题，能让人精神抖擞。

这道题的意思就好比刷墙，第一次刷地较淡，第二次再刷就用更浓的。

题目的意思是：

有小朋友 `num_people = 4`，那么就有数组 `['', '', '', '']`。

这时候开始派发糖果 `candies == 11`：

```
1 => [1, '', '', '']
2 => [1,  2, '', '']
3 => [1,  2,  3, '']
4 => [1,  2,  3,  4]
5 => [2,  2,  3,  4]
```

到了第五轮的时候，我们还剩 `11 - 1 - 2 - 3 - 4 = 1` 颗糖，所以第 1 个小朋友就有 `1 + 1 = 2` 颗糖了。

懂了题目意思，开始解题：

> 暴力破解

```js
const distributeCandies = (candies, num_people) => {
  const result = Array.from(Array(num_people), () => 0);
  let candy = 0;
  while (candies) {
    for (let i = 0; i < num_people; i++) {
      candy++;
      if (candies - candy > 0) {
        result[i] += candy;
        candies -= candy;
      } else {
        result[i] += candies;
        candies = 0;
        break;
      }
    }
  }
  return result;
};
```

按照题目要求，我们做了以下步骤：

1. 通过 `Array.from()` 生成一个长度为 `num_people` 的数组，数组元素全部为 0。
2. 设置当前糖果 `candy` 为 0。
3. 通过 `while()` 判断当前是否还剩糖果，如果不剩则终止循环。
4. 通过 `for()` 遍历，进行糖果的分配，如果当前糖果有剩余，那么我们就将 `candy` 分配给当前小朋友；如果当前糖果没剩余，那么我们就将 `candies` 都丢给当前小朋友，并告诉 `while()` 糖果没有了。

这样我们就解决了这道题。

Submit 提交：

```js
Accepted
* 27/27 cases passed (56 ms)
* Your runtime beats 95.28 % of javascript submissions
* Your memory usage beats 29.67 % of javascript submissions (34.6 MB)
```

如果小伙伴还有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library