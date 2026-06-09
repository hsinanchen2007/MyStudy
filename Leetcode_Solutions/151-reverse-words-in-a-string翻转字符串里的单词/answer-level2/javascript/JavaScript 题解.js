### 解题思路

1. 首先明确输入的参数是一个字符串，要反转字符串里的单词

2. 去除首尾空格

3. 每个单词之间是用空格隔开的，可以利用这一点，分隔单词，存到数组里

4. 数组反转有两种思路

- 直接用内置方法 reverse

- 倒序遍历数组，依次加进新的数组

5. 数组转字符串，可以用 join 方法

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
  const str = s.trim();
  const arr = str.split(/\s+/);
  const len = arr.length - 1;
  let res = [];

  for (let i = len; i >= 0; i--) {
    const item = arr[i];
    res.push(item);
  }
  return res.join(' ');
};
```