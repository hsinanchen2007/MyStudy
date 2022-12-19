### 解题思路
- 正则替换“()”
- 返回剩余字符串的长度

### 结果
执行用时:84 ms, 在所有 JavaScript 提交中击败了73.77%的用户
内存消耗 :36.2 MB, 在所有 JavaScript 提交中击败了13.64%的用户

### 代码

```javascript
/**
 * @param {string} S
 * @return {number}
 */
var minAddToMakeValid = function(S) {
  if (S.length) {
    return deleRepeat(S);
  } else {
    return 0;
  }
  
  function deleRepeat(S) {
    while (S.length) {
      let temp = S;

      S = S.replace('()', '');

      if (S === temp) {
        return S.length;
      }
    }

    return 0;
  }
};
```