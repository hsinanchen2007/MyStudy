没使用任何高级Api,纯手动处理各种情况,请各位多提意见,因为leetcode用全局变量容易出Bug,特别多传了个参数.

```javascript []
/**
 * @requires 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * @param {number} x
 * @param {number} n
 * @return {number}
 */

var myPow = function(x, n) {
  var cache = { nmsl: "fuck" };

  if (n < 0) {
    return 1 / powLogN(x, -n, cache);
  } else {
    return powLogN(x, n, cache);
  }
};

//根据公式2^32 = 2^16 * 2^16,使用二分法分解计算,复杂度为O(Log2N)
var powLogN = function(x, n, cache) {
  if (n === 1) {
    return x;
  }
  if (n === 0) {
    return 1;
  }
  /*
   * 由于我们用的JavaScript,没有int类型,只有number类型,所以不能单纯使用n/2去取幂值
   * 所以我准备做一个数组,构造一把尺子,用这把尺子去切分n,形成x^n = x^i * x^j 其中i为2的次方
   * */
  var ruler = [1];
  var max = 1;
  while (max <= n) {
    max = 2 * max;
    ruler.push(max);
  }
  //执行n为非2的x次方的情况
  return powLogNComp(x, n, ruler, undefined, cache);
};

function powLogNComp(x, n, ruler, lastIndex, cache) {
  if (n === 1) {
    return x;
  }
  if (n === 0) {
    return 1;
  }
  var i, j; //n = i + j
  if (!lastIndex) {
    lastIndex = ruler.length - 1;
  }
  //从尺子中找出最大的小于n的数i,作为下次递归的n传给两个递归函数
  for (var index = lastIndex; index >= 0; index--) {
    if (ruler[index] <= n) {
      i = ruler[index];
      j = n - i;
      lastIndex = index;
      break;
    }
  }
  //i为2的x次方,使用powLog2NComp递归求值,j不一定为2的x次方,需要powLogNComp递归求值,使用尾递归降低空间复杂度
  return powLog2NComp(x, i, cache) * powLogNComp(x, j, ruler, lastIndex, cache);
}

//n为2的x次方,可以放心的使用二分法,不会出现除以2后有小数的情况
function powLog2NComp(x, n, cache) {
  if (n === 1) {
    return x;
  }
  if (n === 0) {
    return 1;
  }
  var subResult; //定义n = n / 2时的结果
  if (cache[n / 2 + ""] !== undefined) {
    subResult = parseFloat(cache[n / 2 + ""]);
  } else {
    subResult = powLog2NComp(x, n / 2, cache);
    cache[n / 2 + ""] = subResult + "";
  }
  //二分法递归求值, 使用尾递归降低空间复杂度
  return subResult * subResult;
}
```
