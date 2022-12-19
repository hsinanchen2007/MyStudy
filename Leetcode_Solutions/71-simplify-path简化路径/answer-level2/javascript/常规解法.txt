### 结果
执行用时 : 88 ms, 在所有 JavaScript 提交中击败了81.38% 的用户
内存消耗 : 36.5 MB, 在所有 JavaScript 提交中击败了17.48% 的用户

### 思路
- 将路径转化为数组
- 遇到".."执行pop()
- 遇到非空和非‘.’执行push

### 答案
```javascript
var simplifyPath = function(path) {
  let arr = path.split('/');
  let result = [];

  arr.forEach((item) => {
    if (item === '..') {
      result.pop();
    } else if (item !== '.' && item !== '') {
      result.push( '/' + item);
    }
  });

  return (result.length ? result.join('') : '/');
};
```