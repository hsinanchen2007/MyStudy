利用Array.prototype.shift和Array.prototype.push操作数组，最后归并输出结果


```JavaScript
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
  let result = [];
  while (ops.length>0) {
    let temp =  ops.shift();
    if (temp === 'C') {
      result.pop()
    } else if (temp === 'D') {
      result.push(2 * result[result.length-1])
    } else if (temp === '+') {
      result.push(result[result.length-2]+result[result.length-1])
    } else result.push(Number(temp))
  }
  return result.reduce((total, currentValue) => total + currentValue, 0)
};
```