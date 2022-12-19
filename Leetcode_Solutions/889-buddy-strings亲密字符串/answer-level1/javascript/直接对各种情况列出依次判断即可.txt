> 68ms,36.1M。
```javascript []
/**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
  if (A.length !== B.length) return false; // 长度不同直接false
  if (A === B) { // 字符串相同且存在重复字符则true，不存在重复字符就false
    if (new Set(A).size < A.length) return true; // 少写点代码直接用Set
    return false;
  }
  // 遍历一遍存在大于2个字符串不同则false；记下第一次不同字符时的index和第二次不同时的字符比较是否符合交换条件
  for (let i = 0, count = 0, errIndex = null; i < A.length; i++) {
    if (A[i] !== B[i]) {
      count++;
      if (count > 2) return false;
      else if (count === 1) errIndex = i;
      else if (A[i] !== B[errIndex] || B[i] !== A[errIndex]) return false;
    }
  }
  return true;
};
```
