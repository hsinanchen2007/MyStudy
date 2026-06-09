话不多说，直接上代码：

> 暴力破解

```js
/**
 * @name 字符串的最大公因子
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
const gcdOfStrings = (str1, str2) => {
  const str = str1.split('');
  const length1 = str1.length;
  const length2 = str2.length;
  while (str.length) {
    const length = str.length;
    if (
      length1 % length === 0
      && length2 % length === 0
      && str.join('').repeat(length1 / length) === str1
      && str.join('').repeat(length2 / length) === str2
    ) {
      return str.join('');
    }
    str.pop();
  }
  return '';
};
```

步骤分析：

1. 首先，我们先设置 `str` 为 `str1` 的的数组形态，然后设置 `length1` 和 `length2` 为对应 `str1` 和 `str2` 的长度。
2. 我们通过不停的 `pop()` 数组 `str` 的元素，让 `str` 慢慢变短。
3. 设置 `length` 为 `str.length`，判断 `length` 是否为 `length1` 和 `length2` 的公因子，如果是，则进而判断它重复 n 次后是否等于 `str1`/`str2`。
4. 如果条件 3 成立，则返回字符串；如果不成立，则返回空串 `''`。

Submit 提交如下：

```js
Accepted
* 103/103 cases passed (68 ms)
* Your runtime beats 61.19 % of javascript submissions
* Your memory usage beats 32.56 % of javascript submissions (35.3 MB)
```

看下大佬的操作，能学到更多：

> gcd 算法

```js
/**
 * @name 欧几里得算法
 * @param {number} a 
 * @param {number} b 
 * @return {number}
 */
const gcd = (a, b) => {
  if (b === 0) {
    return a;
  }
  return gcd(b, a % b);
}
/**
 * @name 字符串的最大公因子
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
const gcdOfStrings = (str1, str2) => {
  if (str1 + str2 !== str2 + str1) {
    return '';
  };
  return str1.substring(0, gcd(str1.length, str2.length));
};
```

1. 首先，如果两个字符串有最大公因子，那么 `str1 + str2 === str2 + str1`，反正直接返回 `''`。
2. 然后，通过欧几里得算法（gcd 算法）辗转相除，求出最大公因数。
3. 最后，截取 `str1` 中的 0 到最大公因数的长度即可。

Submit 提交：

```js
Accepted
* 103/103 cases passed (68 ms)
* Your runtime beats 61.19 % of javascript submissions
* Your memory usage beats 65.12 % of javascript submissions (33.9 MB)
```

这样，我们就完成了这道题的破解。

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library