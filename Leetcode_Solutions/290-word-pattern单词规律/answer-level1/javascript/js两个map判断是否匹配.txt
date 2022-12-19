```js
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
  let pointer = 0; // pattern的指针
  let start = 0;    // 上一个空格后的首字母位置
  let amapb = {};   // key: pattern.item,  value: str.slice
  let bmapa = {};   // key: str.slice,  value: pattern.item
  str += " "; // 加多个空格，方便下面的最后一次遍历
  for (let i = 0; i < str.length; i++) {
    if (str[i] === " ") {
      if (pointer === pattern.length) { // 说明str空格过量了
        return false;
      }
      const slice = str.substring(start, i);
      if (amapb[pattern[pointer]] || bmapa[slice]) {
        if (
          amapb[pattern[pointer]] !== slice ||
          bmapa[slice] !== pattern[pointer]
        ) {
          return false;
        }
      } else {
        amapb[pattern[pointer]] = slice;
        bmapa[slice] = pattern[pointer];
      }
      pointer++;
      start = i + 1;
    }
  }
  if (pointer !== pattern.length) {
    return false;
  }
  return true;
};
```