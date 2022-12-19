```JS
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function (s, k) {
  if (k == 0 || s == '') return s;
  let sArr = s.split('')
  let res = ''
  for (let i = 0; i < sArr.length; i += k) {

    if ((i / k) % 2 == 0) {
      res += sArr.slice(i, i + k).reverse().join('')
    } else {
      res += sArr.slice(i, i + k).join('')
    }
  }
  return res
};
```