比较有价值意义以及争议的一道题，show 一下自己写的和看到大佬写的：

> 哈希表

```js
const letterCasePermutation = (S) => {
  let map = [];
  for (let i = 0; i < S.length; i++) {
    if (i === 0) {
      map = [...new Set([S[0].toLowerCase(), S[0].toUpperCase()])];
    } else {
      map = map.filter(item => item.length === i);
      const upper = S[i].toUpperCase();
      const lower = S[i].toLowerCase();
      const length = map.length;
      for (let i = 0; i < length; i++) {
        if (map.findIndex(item => item === map[i] + upper) === -1) {
          map.push(map[i] + upper);
        }
        if (map.findIndex(item => item === map[i] + lower) === -1) {
          map.push(map[i] + lower);
        }
      }
    }
  }
  return map.filter(item => item.length === S.length);
};
```

思路为：

1. 设置 `map` 为哈希表（没有使用 `Map`，后面会提及为啥）；
2. 通过 `for` 遍历 `S`；
3. 判断：如果是第一次的时候，`i === 0`，进行 `map` 的初始化，即 `[...new Set(arr)]`，这样可以去重开头为数字的情况。
4. 判断：如果不是第一次，`i !== 0`，那么我们做以下步骤：
5. 步骤 1：通过 `filter` 过滤掉长度不符合的字符串，表明之前的 out 了，被淘汰了。
6. 步骤 2：设置 `upper`、`lower` 为当前 `S[i]` 对应的大小写字母，当然，如果是数字也没问题，下面会过滤掉。
7. 步骤 3：通过 `for` 遍历 `map` 的长度，注意这里使用 `length` 来代替 `map.length`，因为下面步骤 `map` 会不停增长长度，如果不写死，那么就造成死循环了。
8. 步骤 4：通过 `findIndex` 查找 `map` 内里有没有元素，和当前元素相加是不会重复的。如果是，则添加到 `map` 中
9. 最后，再通过一次 `filter` 将等同于 `S.length` 长度的字符串暴露出去。

Submit 提交如下：

```js
Accepted
* 63/63 cases passed (752 ms)
* Your runtime beats 5.04 % of javascript submissions
* Your memory usage beats 5.17 % of javascript submissions (52 MB)
```

提交信息残暴如斯，已经不再是哈希了，而是暴力破解了~

绞尽脑汁拿了个差生评价，咱们只能参考借鉴下优等生的题解了：

> 优生解法一：递归

```js
const letterCasePermutation = function f(str) {
  if (str.length === 0) {
    return [''];
  }
  const a = str[0];
  const b = [...new Set([a.toLowerCase(), a.toUpperCase()])];
  if (str.length === 1) {
    return b;
  }
  return letterCasePermutation(str.slice(1)).reduce((r, c) => [...r, ...b.map(m => m + c)], []);
};
```

好处是：代码精简

坏处是：看不懂，或者说，一下子难以理解

Submit 提交：

```js
Accepted
* 63/63 cases passed (160 ms)
* Your runtime beats 7.56 % of javascript submissions
* Your memory usage beats 5.17 % of javascript submissions (43.7 MB)
```

> 优生解法二：回溯算法

```js
const letterCasePermutation = S => {
  const res = [];
  const backtrack = (start, s) => {
    res.push(s);
    for (let i = start; i < s.length; i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        backtrack(i + 1, s.slice(0, i) + s[i].toUpperCase() + s.slice(i + 1));
      } else if (s[i] >= 'A' && s[i] <= 'Z') {
        backtrack(i + 1, s.slice(0, i) + s[i].toLowerCase() + s.slice(i + 1));
      }
    }
  };
  backtrack(0, S);
  return res;
};
```

假设已有字符串 `ab2`，按照这边的回溯，是怎么一回事？

1. 构造递归树；
2. 依次递归遍历。

咱们按照代码理解：

```js
// ...代码省略
const backtrack = (start, s) => {
 console.log('------');
 console.log(start);
 console.log(s);
 // ...代码省略
}
// ...代码省略
```

我们往代码中插入 3 个 `console.log`，方便观察：

```
------
0
ab2
------
1
Ab2
------
2
AB2
------
2
aB2
```

它依次执行了：

```js
backtrack(0, 'ab2'); ->

backtrack(1, 'Ab2');
backtrack(2, 'aB2'); ->

backtrack(2, 'AB2');
```

看到这里，如果你没有感到 **恍然大悟**，那么你可以将代码放到编辑器上，看看 `'a1b2c3'` 的打印情况。

简直妙不可言~

Submit 提交：

```js
Accepted
* 63/63 cases passed (88 ms)
* Your runtime beats 63.87 % of javascript submissions
* Your memory usage beats 55.17 % of javascript submissions (37.8 MB)
```

更多 JavaScript 解析 LeetCode 题目，欢迎关注公众号 【飘飞的心灵】 或者 GitHub：https://github.com/LiangJunrong/document-library