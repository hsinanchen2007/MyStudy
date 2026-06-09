首先，需要知道的是，JavaScript 毕竟非常灵活：

> 【Plan A】一行求解

```js
const defangIPaddr = (address) => address.split('').map(item => item === '.' ? `[.]` : item).join('');
```

Submit 提交：

```js
Accepted
* 62/62 cases passed (60 ms)
* Your runtime beats 81.63 % of javascript submissions
* Your memory usage beats 30.27 % of javascript submissions (33.8 MB)
```

> 【Plan B】两行求解

```js
const defangIPaddr = (address) => {
  return address.split('').reduce((prev, next) => {
    return next === '.' ? prev + '[.]' : prev + next;
  });
};
```

Submit 提交：

```js
Accepted
* 62/62 cases passed (92 ms)
* Your runtime beats 6.69 % of javascript submissions
* Your memory usage beats 29.4 % of javascript submissions (33.8 MB)
```

> 【Plan C】正常求解

```js
const defangIPaddr = (address) => {
  let result = '';
  for (let i = 0; i < address.length; i++) {
    if (address[i] === '.') {
      result += '[.]';
    } else {
      result += address[i];
    }
  }
  return result;
};
```

Submit 提交：

```js
Accepted
* 62/62 cases passed (60 ms)
* Your runtime beats 81.63 % of javascript submissions
* Your memory usage beats 41.31 % of javascript submissions (33.8 MB)
```

小伙伴喜欢哪款随意拿去，更多的 **jsliang** 就不多逼逼了。

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library