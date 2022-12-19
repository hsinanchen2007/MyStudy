
- 思路见题解
```
var fractionToDecimal = function(numerator, denominator) {
  let str = '';
  // 处理正负号
  if (numerator * denominator < 0) str = '-'
  numerator = Math.abs(numerator)
  denominator = Math.abs(denominator)
  // 处理整数部分
  let num = Math.floor(numerator/denominator);
  if (numerator - denominator * num === 0) {
    return str + num
  }
  str += num
  str += '.';
  numerator -= denominator * num;
  // numerator 表示余数
  let chche = [numerator];
  while(numerator !== 0) {
    numerator*=10
    if (numerator< denominator) {
      chche.push(numerator)
      str += 0
      continue;
    }
    let num = Math.floor(numerator/denominator)
    str += num
    numerator -= denominator * num;
    // 出现相同的余数 则退出
    if (chche.includes(numerator)) {
      break;
    }
    chche.push(numerator)
  }
  if (numerator === 0) return str;
  let index = str.indexOf('.') + 1
  let _index = chche.indexOf(numerator)
  return str.slice(0, index+_index) + '(' + str.slice(index+_index) + ')'
};
```
