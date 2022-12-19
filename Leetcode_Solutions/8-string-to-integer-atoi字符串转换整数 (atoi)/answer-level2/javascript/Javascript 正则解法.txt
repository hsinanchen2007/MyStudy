```javascript
/**
 * @param {string} str
 * @return {number}
 * 76ms 96.28%
 * 35.7mb 78.60%
 */
var myAtoi = function(str) {
  let ret = str.match(/^\s*[+-]?\d+/);
  if (ret !== null) {
    let _ret = Number(ret[0]);
    return _ret >= 0 ? Math.min(_ret, 2**31 - 1) : Math.max(_ret, (-2)**31);
  } else {
    return 0;
  }
};
```