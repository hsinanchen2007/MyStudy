### 解题思路
1.首先判断负数的情况
2.转化为字符串，再转为数组进行反转
3.最后数组转为字符串，再和之前的值进行比较
不太清楚，不把数字转为字符串的解法，还需努力，加油！
### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x < 0) return false;
    let val = JSON.stringify(x);
    return val === val.split('').reverse().join('')
};
```