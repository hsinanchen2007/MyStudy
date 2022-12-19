由于只会用到前一个数和前前个数，因此用两个变量代替即可

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function(num) {
  const numStr = String(num);
  if (!numStr.length) return '';
  let before = 1;
  if (numStr.length === 1) return before;
  let after = Number(numStr[ 0 ] + numStr[ 1 ]) > 25 ? 1 : 2;
  let preStr = numStr[ 1 ];
  for (let i = 2; i < numStr.length; i++) {
    const temp = after;
    if (preStr !== '0' && Number(preStr + numStr[ i ]) <= 25) {
      after += before;
    }
    before = temp;
    preStr = numStr[ i ];
  }
  return after;
};
```
