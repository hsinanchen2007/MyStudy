使用递归的方式
```js
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  // 1.从最后一项开始加 1
  plus(digits.length - 1, digits);
  
  function plus(index, arr) {
    // 2.加 1
    var result = ++arr[index];
    
    // 3.如果超了
    if (result === 10) {
      // 4.判断是不是第一位超的
      if (arr[0] === 10) {
        // 5.是的话就改为 0 ，且在前面插入 1
        arr[0] = 0;
        
        arr.unshift(1);
      } else {
        // 6.不是的话将索引那一位也改为 0，并且往前递归
        arr[index] = 0;
        
        // 7.递归
        plus(--index, arr);
      }
    }
  }
  
  return digits;
};
```
