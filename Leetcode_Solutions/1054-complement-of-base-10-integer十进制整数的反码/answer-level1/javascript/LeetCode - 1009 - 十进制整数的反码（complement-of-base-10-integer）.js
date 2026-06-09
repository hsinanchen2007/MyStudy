看完题目就有思路了，主要是十进制转二进制的基础操作，这里从浅入深，逐步完善讲解：

> 十进制转二进制

```js
/**
 * @name 十进制转二进制
 * @param {number} num 需要转换的数字
 * @return {string}
 */
const decimalToBinary = (num) => {
  let result = '';
  while (num > 0) {
    result = (num % 2) + result;
    num = Math.floor(num / 2);
  }
  return result;
};
console.log(decimalToBinary(5));
```

打印结果为 `'101'`，这样我们就有了十进制转二进制的方法，这道题的答案呼之欲出：

> 暴力破解

```js
/**
 * @name 十进制转二进制
 * @param {number} num 需要转换的数字
 * @return {string}
 */
const decimalToBinary = (num) => {
  if (num === 0) {
    return '0';
  }
  let result = '';
  while (num > 0) {
    result = (num % 2) + result;
    num = Math.floor(num / 2);
  }
  return result;
};

/**
 * @name 十进制整数的反码
 * @param {number} N
 * @return {number}
 */
const bitwiseComplement = (N) => {
  const binary = decimalToBinary(N);
  let newBinary = '';
  for (let i = 0; i < binary.length; i++) {
    if (binary[i] === '1') {
      newBinary += '0';
    } else {
      newBinary += '1';
    }
  }
  return parseInt(newBinary, 2);
};

console.log(bitwiseComplement(7)); // 0
```

Submit 提交：

```js
Accepted
* 128/128 cases passed (60 ms)
* Your runtime beats 84.91 % of javascript submissions
* Your memory usage beats 54.22 % of javascript submissions (33.7 MB)
```

但是，看到 `parseInt(newBinary, 2)`，小伙伴应该瞬间明悟：

* 卧槽有原生方法将二进制转十进制，那么应该也有方法将十进制转二进制的吧！

是的：

> 【优化一】利用原生 API

```js
const bitwiseComplement = (N) => {
  const binary = N.toString(2);
  let newBinary = '';
  for (let i = 0; i < binary.length; i++) {
    if (binary[i] === '1') {
      newBinary += '0';
    } else {
      newBinary += '1';
    }
  }
  return parseInt(newBinary, 2);
};
```

Submit 提交：

```js
Accepted
* 128/128 cases passed (72 ms)
* Your runtime beats 32.08 % of javascript submissions
* Your memory usage beats 51.81 % of javascript submissions (33.8 MB)
```

并不是我乱写的提交结果，但是我自己写的方法是 `runtime beats 84.91 %`，原生是 `runtime beats 32.08 %`。

因为原生考虑的不仅仅是这么点内容，你懂的。

> 【优化二】简化暴力破解

```js
const bitwiseComplement = (N) => {
  let binary = '';
  while (N > 0) {
    if (N % 2 === 0) {
      binary = '1' + binary;
    } else {
      binary = '0' + binary;
    }
    N = Math.floor(N / 2);
  }
  return parseInt(binary || '1', 2);
};
```

Submit 提交：

```js
Accepted
* 128/128 cases passed (60 ms)
* Your runtime beats 84.91 % of javascript submissions
* Your memory usage beats 54.22 % of javascript submissions (33.7 MB)
```

这里我们直接将转换的方法搬过来，然后需要直接转换 1 和 0 即可。

最后需要注意的是，0 会被转换成 NaN，所以我们直接给个 `'1'` 就好~

如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library