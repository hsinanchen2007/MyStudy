# 35 - 杨辉三角2

## 题目

给定一个非负索引 *k*，其中 *k* ≤ 33，返回杨辉三角的第 *k* 行。

![img](https://pic.leetcode-cn.com/e4f962a630c04f4869438a5a5ee8384da74f04c7adb0e88d84c9f8938d8fec86.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

> 输入: 3
> 输出: [1,3,3,1]

进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

## 解答

返回第k行，拿到题目就有两个想法。【其实是在返回k+1行，第一行他没算】

可以直接把杨辉三角的代码，返回最后一行；

```js
var getRow = function (rowIndex) {
  const result = [];
  for (let i = 0; i < rowIndex + 1; i++) {
    const subArr = [1];
    for (let j = 1; j <= (i >>> 1); j++) {
      subArr[j] = result[i - 1][j - 1] + result[i - 1][j];
    }
    for (let k = (i >>> 1) + 1; k <= i; k++) {
      subArr[k] = subArr[i - k]
    }
    result.push(subArr);
  }
  return result[result.length - 1]
};
```

> Runtime: 56 ms, faster than 61.34% of JavaScript online submissions for Pascal's Triangle II.
>
> Memory Usage: 33.9 MB, less than 65.19% of JavaScript online submissions for Pascal's Triangle II.

也有数学方法可以直接得出某一行的代码。

```js
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function (numRows) {
  let res = [];
  for (let i = 0; i < numRows + 1; i++) {
    res.push(C(numRows, i))
  }
  return res;
};
/**
* 组合数
* @param n
* @param r
* @returns {number}
* @constructor
*/
const C = function (n, r) {
  if (n === 0) return 1;
  return F(n) / F(r) / F(n - r);
}
/**
* 阶乘
* @param n
* @returns {number}
* @constructor
*/
const F = function (n) {
  var s = 1;
  for (var i = 1; i <= n; i++) {
    s *= i;
  }
  return s;
}

// 阶乘也可以用尾递归写：
var factor = function (n, total = 1) {
  if (n === 1) {
    return 1
  } else {
    return factor(n - 1, n * total)
  }
}
```

> Runtime: 48 ms, faster than 93.64% of JavaScript online submissions for Pascal's Triangle II.
>
> Memory Usage: 34.3 MB, less than 33.33% of JavaScript online submissions for Pascal's Triangle II.