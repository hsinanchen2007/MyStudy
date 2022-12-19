### 解题思路
就是把一个整数转成一个个位数的数组，再遍历数组就欧克了

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function (n) {
    var ji = 1;
    var sum = 0;
    var num = n.toString().split('')
    for (var i = 0; i < num.length; i++) {
        ji *= parseInt(num[i])
        sum += parseInt(num[i])
    }
    return ji - sum
};
```