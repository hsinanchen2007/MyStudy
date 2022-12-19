题目意思是：

1. 假设有 A：`[3, -1, 0, 2]`，有 K：`3`。
2. 我们需要对 A 进行 K 次操作，以取得最大数组的和。
3. 在上面的数组中，我们对 `-1` 进行 1 次取反，得到 `1`，然后对其他任意数进行两次取反，得到原数，最终结果为 `0 + 1 + 2 + 3 = 6`。

OK，题意倒是理解了，但是不知道怎么下手，先尝试尝试吧：

> 区分正数、负数以及 0

```js
const largestSumAfterKNegations = (A, K) => {
  const positiveNumbers = []; // 正数
  const negativeNumbers = []; // 负数
  let zero = false; // 是否有 0
  for (let i = 0; i < A.length; i++) {
    if (A[i] > 0) {
      positiveNumbers.push(A[i]);
    } else if (A[i] < 0) {
      negativeNumbers.push(A[i]);
    } else {
      zero = true;
    }
  }
  positiveNumbers.sort((a, b) => a - b);
  negativeNumbers.sort((a, b) => a - b);
  console.log('正数集合：', positiveNumbers);
  console.log('负数集合：', negativeNumbers);
  console.log('是否有 0：', zero);
};

console.log(largestSumAfterKNegations([2, -3, -1, 5, -4, 0], 2));
```

打印出来：

```
正数集合： [ 2, 5 ]
负数集合： [ -4, -3, -1 ]
是否有 0： true
```

现在最主要的是看 K，我们要做到的是尽可能把负数给转换成正数，以取得最大化的数组和。

所以：

1. 【`K <= negativeNumbers.length`】。如果 K 小于负数集合的长度，那么我们直接从小到大取反 K 个数字，求和即可（负数最小的取反得到的值比较大，例如 `-4 < -3`，`-(-4) > -(-3)`）。
2. 【`K > negativeNumbers.length, zero = true`】如果 K 大于负数集合的长度，并且包含 0，那么将所有负数集合中的数字变成正数，其他次数作用于 0 即可，求和即可。
3. 【`K > negativeNumbers.length, zero = false, (K - negativeNumbers.length) % 2 === 0`】如果 K 大于负数集合的长度，并且不包含 0，并并且多出来的次数是偶数，那么我们还是将所有负数集合中的数字变成正数，求和即可。（因为多出来的次数是偶数，所以我们可以重复对一个数字求反：对 4 求反 2 次还是 4）
4. 【`K > negativeNumbers.length, zero = false, (K - negativeNumbers.length) % 2 === 1`】次条件类似于判断 3，但是有个不同的是多出来的次数是奇数，所以我们还需要对绝对值最小的值进行一次取反操作~

分析完毕，答案呼之欲出：

> 暴力破解

```js
const largestSumAfterKNegations = (A, K) => {
  // 1. 定义各种字段
  const positiveNumbers = []; // 正数
  const negativeNumbers = []; // 负数
  let zero = false; // 是否有 0
  let min = 101; // -100 <= A[i] <= 100
  let needMin = false; // 是否需要对最小值操作
  
  // 2. 获取正数、负数和 0
  for (let i = 0; i < A.length; i++) {
    if (A[i] > 0) {
      positiveNumbers.push(A[i]);
    } else if (A[i] < 0) {
      negativeNumbers.push(A[i]);
    } else {
      zero = true;
    }
    min = Math.min(min, Math.abs(A[i]));
  }
  
  // 3. 对正数集合和负数集合进行重新排序
  positiveNumbers.sort((a, b) => a - b); // 正数排序：[1, 2, 3]
  negativeNumbers.sort((a, b) => a - b); // 负数排序：[-3, -2, -1]

  // 4. 进行取反操作
  const negLength = negativeNumbers.length;
  if (K <= negLength) {
    for (let i = 0; i < K; i++) {
      negativeNumbers[i] = - negativeNumbers[i];
    }
  } else if (K > negLength && zero) {
    for (let i = 0; i < negLength; i++) {
      negativeNumbers[i] = - negativeNumbers[i];
    }
  } else if (K > negLength && !zero && (K - negLength) % 2 === 0) {
    for (let i = 0; i < negLength; i++) {
      negativeNumbers[i] = - negativeNumbers[i];
    }
  } else if (K > negLength && !zero && (K - negLength) % 2 === 1) {
    for (let i = 0; i < negLength; i++) {
      negativeNumbers[i] = - negativeNumbers[i];
    }
    needMin = true;
  }

  // 5. 汇总计算
  if (needMin) {
    return [...negativeNumbers, ...positiveNumbers].reduce((prev, next) => prev + next) - (min * 2);
  } else {
    return [...negativeNumbers, ...positiveNumbers].reduce((prev, next) => prev + next);
  }
};
```

这里为了方便观众老爷观看，所以取反操作 **jsliang** 并没有对相同的操作进行合并，否则可以变成：

```js
if (K <= negLength) {
 for (let i = 0; i < K; i++) {
   negativeNumbers[i] = - negativeNumbers[i];
 }
} else if (K > negLength && !zero && (K - negLength) % 2 === 1) {
 for (let i = 0; i < negLength; i++) {
   negativeNumbers[i] = - negativeNumbers[i];
 }
 needMin = true;
} else {
 for (let i = 0; i < negLength; i++) {
   negativeNumbers[i] = - negativeNumbers[i];
 }
}
```

以上，就是 **jsliang** 对本题的解法~

当然，如果小伙伴们有更好的解法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library