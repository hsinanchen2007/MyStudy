### Analyze

可以用栈的思想来完成解题;

1. 使用 '/' 分割 path 为得到数组;
2. 对以下几种情况分别处理:
   1. 如果遇见 '.' 或者 '', 则忽略;
   2. 如果遇见字母, 则将其推入栈的末尾;
   3. 如果遇见 '..', 则从栈末尾移除一个元素;

```js
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
  const pathArr = path.split('/')
  const stack = []
  for (let i = 0; i < pathArr.length; i++) {
    if (pathArr[i] === '..') {
      stack.pop()
    } else if (pathArr[i] === '.' || pathArr[i] === '') {
      continue
    } else {
      stack.push(pathArr[i])
    }
  }

  return `/${stack.join('/')}`
}
```

### Similar Title

20、150

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)