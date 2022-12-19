![image.png](https://pic.leetcode-cn.com/6a06cc4caeb9572d94ab9f4bbe6a7528800ebc447bd501511b9992c429640fee-image.png)

### 解题思路
```js
  参考作者：「labuladong」
  注意：不要输入转换为数组进行计算，如："3+2*2" => ['3', '+', '2', '*', '2']
  这样的话，数组的操作次数太多，会超时的
```

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */

var calculate = function(s) {
  let stack = [],
      sign = '+',
      num = 0,
      sum = null,
      number = '0123456789',
      top = null,
      index = 0;
  
  while (index <= s.length) {
    let c = null, willStop = false;
    if (index === s.length) {
      c = '+'; // 随便给个符号为了再触发一次循环，计算最后一个数
      willStop = true;
    } else {
      c = s.charAt(index);
      index++;
    }
    
    if (c === ' ') continue;
    
    if (number.indexOf( c ) !== -1) {
      num = num * 10 + (c - '0');
    }
    else {
      switch (sign) {
        case '+':
          stack.push( num );
          num = 0;
          sign = c;
          break;
        case '-':
          stack.push( -num );
          num = 0;
          sign = c;
          break;
        case '*':
          top = stack.pop();
          stack.push( top * num );
          num = 0;
          sign = c;
          break;
        case '/':
          top = stack.pop();
          if (top >= 0 && num >= 0) {
            stack.push( Math.floor(top / num) );
          } else {
            stack.push( Math.ceil(top / num) )
          }
          num = 0;
          sign = c;
          break;
      }
    }
    
    if (willStop) break;
  }
  
  sum = stack.reduce((prev, curr) => {
    return prev + curr;
  }, 0);
  
  return sum;
};
```