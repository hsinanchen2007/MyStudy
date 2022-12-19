# 18 - 加一

## 题目

给定一个由**整数**组成的**非空**数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

> 输入: [1,2,3]
> 输出: [1,2,4]
> 解释: 输入数组表示数字 123。

示例 2:

> 输入: [4,3,2,1]
> 输出: [4,3,2,2]
> 解释: 输入数组表示数字 4321。

## 解答

简言之，就是一个数字，一位位变成一个数组。然后输出值需要将其加一。

也就是说，要给数组最后一位数加一。如果有进位，就一位位向前进。

### 变成数字再做运算

可以把数组变成字符串，变成数字，加一，再倒回去。

```js
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  const str = digits.join("");
  const ans_str = parseInt(str, 10) + 1 + "";
  return ans_str.split("").map(Number);
};
```

我觉得是可行的，但实际测下来不可行。反例：`[6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3]`。

在js里面，输入`6145390195186705543`，会自动变成`6145390195186705000`。

![image-20190713203942672](https://pic.leetcode-cn.com/ef06ba7c58c06f5429672cffe35a94f18acea200b5990b164f172efe981c8372.jpg)

若是输入`61453901951867055`会变成`61453901951867060`。

![image-20190713203926144](https://pic.leetcode-cn.com/04764a9a0146723a26722be5a1940b98bda03b3642aaff94ef6d2bfbbcf658c7.jpg)

因为js的[最大安全整数](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Number/MAX_SAFE_INTEGER)是$2^{53}-1$，即`9007199254740991`。如果超过这个值，那么任何的计算都会失去精度【可能和内部靠16位存储有关】。也就是上面这些数字的显示情况。

不过查了半天发现，大于上限的数字可以用`BigInt`来表达：[BigInt](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/BigInt)。也就是在数字后面加一个`n`，如`1n`。

```js
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  const str = digits.join("");
  const ans_str = BigInt(str) + 1n + "";  // 转成bigint
  return ans_str.split("").map(Number);
};
```

> Runtime: 44 ms, faster than 99.44% of JavaScript online submissions for Plus One.
>
> Memory Usage: 34.1 MB, less than 8.13% of JavaScript online submissions for Plus One.

`bigint`类似于一种特殊的类型，有别于`number`。因此不能和`number`混着计算，也不能用`math`的方法。简言之就是为存储而生，能做的运算也有限。

### 作为数组直接加一

需要进位就向前一位加一，如果没有前一位，说明是全9，那么就重新做一个数组，第一个是1，后面长度都是0

```js
var plusOne = function(digits) {
  for (let i = digits.length - 1; i >= 0; i--) {
    digits[i]++;
    digits[i] %= 10;
    if (digits[i] !== 0) {
      return digits;
    }
  }
  let arr = new Array(digits.length + 1);
  for (let i = 0; i < digits.length + 1; i++) {
    arr[i] = 0;
  }
  arr[0] = 1;
  return arr;
};
```

> Runtime: 44 ms, faster than 99.44% of JavaScript online submissions for Plus One.
>
> Memory Usage: 33.8 MB, less than 74.62% of JavaScript online submissions for Plus One.

整个程序分为两个部分。第一部分是判断是否需要进位。最开始想到的做法：

```js
...
	for (let i = digits.length - 1; i >= 0; i--) {
    digits[i]++;
    if (digits[i] !== 10) {
      return digits;
    } else {
      digits[i] = 0;
    }
  }
...
```

但这么做的话，运行速度就会明显下降

> Runtime: 64 ms, faster than 21.73% of JavaScript online submissions for Plus One.
>
> Memory Usage: 33.7 MB, less than 94.18% of JavaScript online submissions for Plus One.

上面取余的做法，来自于题解：

> 作者：guanpengchn
>
> 链接：https://leetcode-cn.com/problems/two-sum/solution/hua-jie-suan-fa-66-jia-yi-by-guanpengchn/

第二部分是需要整体多一位的做法。思路是新建一个全为0的数组，然后令第一个元素为1。

有趣的是，许多看起来装逼的写法，速度并不快。

> [创建全0数组](https://segmentfault.com/a/1190000003861423)
>
> [对比网址](https://jsperf.com/zero-filled-array-creation/17)
>
> ![image-20190713221656540](https://pic.leetcode-cn.com/50cfb917dc17800bdfb5ffbae2b3a574323971be3d45e2f8cd904f131a2f8fad.jpg)
>

最快的是最基础的for循环，可能是因为这是最早出来的，所以优化地最好吧。其他的新招式，看就要慢得多了。

所以在解题当中也是用了最快的做法。

#### 第二部分可以更加优雅

第二部分的目的是做一个数组，长度加一位，第一位为1，剩下的都是0。我第一反应就是新建一个数组再赋值。

[@ふたりの距离の概算](https://leetcode-cn.com/u/chitanda-eru) 提出了两种更加优雅的做法：

>  ```javascript
> digits.unshift(1);
> return digits;
> ```
>
> 或者
>
> ```javascript
> return [1, ...digits];
> ```

感觉确实比我之前的做法要简洁直观不少！感觉很酷！

> 执行用时 :72 ms, 在所有 JavaScript 提交中击败了91.84%的用户
>
> 内存消耗 :33.7 MB, 在所有 JavaScript 提交中击败了44.99%的用户

测了几次，发现执行速度差不多，内存略有增加，可能是因为要全部复制一下`digits`数组吧。不过这样代码的可读性就好了很多。

## 测试代码

```js
/**
 *
 * @param {number[]} ans：输入的answer
 * @param {number[]} target：答案
 * @param {number} index：报错标记符
 * @returns {boolean}
 */
const ensure = (ans, target, index) => {
  const Ans = ans.toString();
  const Target = target.toString();
  if (Ans !== Target) {
    wrongMsg(ans, target, index);
    return false;
  } else {
    return true;
  }
};
```

