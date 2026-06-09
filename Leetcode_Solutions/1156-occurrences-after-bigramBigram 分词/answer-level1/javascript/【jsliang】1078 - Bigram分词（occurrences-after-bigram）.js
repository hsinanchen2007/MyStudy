简单难度：

> 暴力破解

```js
const findOcurrences = (text, first, second) => {
  const textArr = text.split(' ');
  const result = [];
  for (let i = 0; i < textArr.length - 2; i++) {
    if (textArr[i] === first && textArr[i + 1] === second) {
      result.push(textArr[i + 2]);
    }
  }
  return result;
};
```

步骤：

1. 先根据 `' '` 空格切割字符串。
2. 设置 `result` 获取最终结果。
3. 通过 2 个游标的移动，获取第三个游标对应的字符串，将其添加进 `result` 中。

打完收工，耗时如下：

```js
Accepted
* 29/29 cases passed (64 ms)
* Your runtime beats 58.56 % of javascript submissions
* Your memory usage beats 49.38 % of javascript submissions (33.8 MB)
```

那肯定会有小伙伴会纠结：我不喜欢用 JavaScript 原生 API 工具，我就喜欢手写，你都不是手写的~

> split 代码实现

```js
const findOcurrences = (text, first, second) => {
  const textArr = [];
  let str = '';
  for (let i = 0; i < text.length; i++) {
    if (text[i] === ' ') {
      textArr.push(str);
      str = '';
    } else {
      str += text[i];
    }
  }
  str.length && textArr.push(str);
  const result = [];
  for (let i = 0; i < textArr.length - 2; i++) {
    if (textArr[i] === first && textArr[i + 1] === second) {
      result.push(textArr[i + 2]);
    }
  }
  return result;
};
```

Submit 提交：

```js
Accepted
* 29/29 cases passed (60 ms)
* Your runtime beats 73.87 % of javascript submissions
* Your memory usage beats 59.26 % of javascript submissions (33.7 MB)
```

enm...那我都直接在字符串上进行切割了，我何不直接在支付串上操作获取 `third` 元素：

> 暴力破解【优化】

```js
const findOcurrences = (text, first, second) => {
  // 1. 定义系列字段
  let flag = 0; // 当前游标
  let firstSite = 0; // 第一个字母游标
  let secondSite = 0; // 第二个字母游标
  const result = []; // 结果值
  let str = ''; // 当前字符串累计

  // 2. 开始搞事
  for (let i = 0; i < text.length; i++) {
    // 2.1 非 ' ' 空字符串下不停累加
    if (text[i] !== ' ') {
      str += text[i];
    }
    // 2.2 如果是 ' ' 或者是字符串末尾，进行结算
    if (text[i] === ' ' || i === text.length - 1) {
      flag++;
      if (firstSite === flag - 2 && secondSite === flag - 1) {
        result.push(str);
      }
      if (str === second && firstSite === flag - 1 && firstSite) {
        secondSite = flag;
      }
      if (str === first) {
        firstSite = flag;
      }
      str = '';
    }
  }
  // 3. 返回最终结果
  return result;
};
```

Submit 提交：

```js
Accepted
* 29/29 cases passed (60 ms)
* Your runtime beats 73.87 % of javascript submissions
* Your memory usage beats 6.17 % of javascript submissions (35.4 MB)
```

你想要的，全都在这了~

如果小伙伴有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~


公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library