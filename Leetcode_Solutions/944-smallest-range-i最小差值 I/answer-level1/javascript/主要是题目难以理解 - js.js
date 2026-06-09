# 27 - 最小差值

## 题目

给定一个整数数组 A，对于每个整数 A[i]，我们可以选择任意 x 满足 -K <= x <= K，并将 x 加到 A[i] 中。

在此过程之后，我们得到一些数组 B。

返回 B 的最大值和 B 的最小值之间可能存在的**最小差值**。

示例 1：

> 输入：A = [1], K = 0
> 输出：0
> 解释：B = [1]

示例 2：

> 输入：A = [0,10], K = 2
> 输出：6
> 解释：B = [2,8]

示例 3：

> 输入：A = [1,3,6], K = 3
> 输出：0
> 解释：B = [3,3,3] 或 B = [4,4,4]


提示：

> 1 <= A.length <= 10000
> 0 <= A[i] <= 10000
> 0 <= K <= 10000

## 解答

题目有些难以理解。。。

> 作者：yunfeihe
> 链接：https://leetcode-cn.com/problems/two-sum/solution/leetcode-908-zui-xiao-chai-zhi-i-smallest-range-i-/

看了他的理解后，我对题目的理解是这样的：

1. 输入的是两个数，一个是数组`A`，另一个是数字`K`
2. 我们要对数组`A`的每个元素，都进行一个替换操作，最终形成数组`B`。
3. 要求的是，这个数组`B`最大值和最小值之间的**最小差值**
4. 这个替换的操作是什么呢？只要元素值落在$-K <= x <= K$这个区间内，就能替换掉数组`A`的元素。

既然替换后的数组，大小差距要最小，即意味着原来的`A`数组，最小值要变得尽可能大，而最大值要变得尽可能小。

换言之，`A`的最小值要用`K`替换，而最大值要用`-K`替换。

那么最小差值，也就是$(A.max - K) - (A.min + K) = A.max - A.min - 2*K$。

```js
var smallestRangeI = function (A, K) {
  let max = Math.max(...A)
  let min = Math.min(...A)
  let target = max - min - 2 * Math.abs(K)
  return target > 0 ? target : 0
};
```

> Runtime: 60 ms, faster than 71.43% of JavaScript online submissions for Smallest Range I.
>
> Memory Usage: 35.2 MB, less than 78.57% of JavaScript online submissions for Smallest Range I.

还看到一个一行解的。。我改造了一下。。

```js
var smallestRangeI = function (A, K) {
  return Math.max(0, Math.max(...A) - Math.min(...A) - 2 * K);
};
```

> Runtime: 56 ms, faster than 88.57% of JavaScript online submissions for Smallest Range I.
>
> Memory Usage: 35.2 MB, less than 78.57% of JavaScript online submissions for Smallest Range I.


