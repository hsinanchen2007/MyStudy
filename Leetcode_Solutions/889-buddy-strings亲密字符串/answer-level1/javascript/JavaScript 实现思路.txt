字符串长度不一致**不符合**条件

字符串长度一致，则：循环遍历对比两个字符串相应位置不同字符的**值**和**数量**
- 如果字符串不同个数大于2**不符合**条件
- 如果字符串不同个数等于2则判断则两个字符交换后是否一致，如果一致则**符合**
- 如果字符串不同个数等于0则需判断字符串是否存在重复字符，如果存在这**符合**


```js
/**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
  if(A.length !== B.length) {
    return false;
  }

  let diffNum = 0;
  let aDiffChar = '';
  let bDiffChar = '';

  for(let i = 0; i < A.length; i++) {
    if(A[i] !== B[i]) {
      if(++diffNum > 2) {
        return false;
      }
      aDiffChar += A[i];
      bDiffChar = B[i] + bDiffChar;
    }
  }

  // 如果是全相同的话，只有存在两个相同的字符串才可以调换
  if(diffNum === 0 && A.length > new Set(A).size) {
    return true;
  }

  if(diffNum !== 2) {
    return false;
  }else {
    return aDiffChar === bDiffChar;
  }
};
```