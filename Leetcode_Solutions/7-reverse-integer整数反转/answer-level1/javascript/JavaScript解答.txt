### 解题思路
这个解是看了别人的答案！ 首先理解题目的这句话：“给出一个 32 位的有符号整数” 也就是二进制，转为十进制就是-512-511之间，然后考虑溢出就可以啦！

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const edeg = 2**31
    const max = edeg - 1
    const min = -edeg
    
    const result = (x > 0 ? 1 : -1) * String(x).split('').filter(x => x !== '-').reverse().join('')
    return result > max || result < min ? 0 : result
};
```