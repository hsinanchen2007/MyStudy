# 34 - 杨辉三角

## 题目

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

![img](https://pic.leetcode-cn.com/b9af76a8c9976d56976fd518d24010a78903f45358823692679bacb16d76b44f.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

> 输入: 5
> 输出:
> [
>      [1],
>     [1,1],
>    [1,2,1],
>   [1,3,3,1],
>  [1,4,6,4,1]
> ]

## 解答

### 直观解

每次都调出上一行的值，然后加出下一行的值。

> 作者：raymond-yan
>
> 链接：https://leetcode-cn.com/problems/two-sum/solution/javascript-ban-ben-by-raymond-yan/

```js
var generate = function (numRows) {
  const result = [];
  if (numRows <= 0) {
    return result;
  }
  for (let i = 0; i < numRows; i++) {
    const subArr = [];
    for (let j = 0; j <= i; j++) {
      if (j > 0 && j < i) {
        subArr.push(result[i - 1][j - 1] + result[i - 1][j]);
      } else {
        subArr.push(1);
      }
    }
    result.push(subArr);
  }
  return result;
};
```

> Runtime: 52 ms, faster than 77.14% of JavaScript online submissions for Pascal's Triangle.
>
> Memory Usage: 33.9 MB, less than 40.30% of JavaScript online submissions for Pascal's Triangle.

### 数学解法

> 作者：infinite-loop
>
> 链接：https://leetcode-cn.com/problems/two-sum/solution/shi-yong-er-xiang-shi-ding-li-gong-shi-ji-suan-yan/

二项式每一项的系数对应杨辉三角的第n行。就直接通过计算二项式的系数，算出该行的值。

```js
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function (numRows) {
  let res = [];
  for (let i = 0; i < numRows; i++) {
    res[i] = [];
    for (let j = 0; j < i + 1; j++) {
      res[i].push(C(i, j));
    }
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

> Runtime: 56 ms, faster than 55.91% of JavaScript online submissions for Pascal's Triangle.
>
> Memory Usage: 34.4 MB, less than 5.47% of JavaScript online submissions for Pascal's Triangle.

### 左右对称，因此只用计算一半

> 作者：buptra_prism
>
> 链接：https://leetcode-cn.com/problems/two-sum/solution/xiao-bai-shua-ti-yang-hui-san-jiao-by-buptra_prism/

```js
var generate = function (numRows) {
  const result = [];
  for (let i = 0; i < numRows; i++) {
    const subArr = [1];
    for (let j = 1; j <= (i >>> 1); j++) {
      subArr[j] = result[i - 1][j - 1] + result[i - 1][j];
    }
    for (let k = (i >>> 1) + 1; k <= i; k++) {
      subArr[k] = subArr[i - k]
    }
    result.push(subArr);
  }
  return result
};
```

> Runtime: 48 ms, faster than 91.19% of JavaScript online submissions for Pascal's Triangle.
>
> Memory Usage: 33.9 MB, less than 45.27% of JavaScript online submissions for Pascal's Triangle.