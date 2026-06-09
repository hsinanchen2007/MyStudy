### 解题思路
首先按照要求来看，传入的数字比须要大于等于2位数，也就是说必须要大于等于10，然后循环取余并取整，每次循环将n除10，直到n小于1结束循环，在每次循环中，将得到的各数相加和相乘。循环结束后，返回要求的差值

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    if (n < 10 || n >= 10e5) {
        return 0
    }
    let add = 0, mul = 1
    while (n > 1) {
        let digit = Math.floor(n % 10)
        n /= 10
        add += digit
        mul *= digit
    }
    return mul - add
};
```