### 解题思路


对 9 取余, 很神奇
### 代码
```js
var addDigits = function(num) {
  return num && (num % 9 ? num % 9 : 9) || 0
}

```

题目说:不用循环, 但是还是写下
```javascript
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    let sub = (num+'').split('').reduce((t,i) => +t + +i)
    while(sub > 9){
      sub = (sub+'').split('').reduce((t,i) => +t + +i)
    }
    return sub
};
```