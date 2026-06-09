## 不能使用临时变量，那只能从加减法或者位操作出发来思考

```
/**
 * @param {number[]} numbers
 * @return {number[]}
 */
var swapNumbers = function(numbers) {
     /**
     * 判断一些数组合理性，以及数组中的两个数是否相等。
     */

    if(!numbers || numbers[0] === numbers[1]) return numbers;
    /**
     * 避免是使用加法，防止溢出
     * 
     * a^b^b = a
     * a^b^a = b
     * 
     * a ^ a = 0
     * 0 ^ a = a
     */
    numbers[0] = numbers[0] ^ numbers[1]
    numbers[1] = numbers[0] ^ numbers[1]
    numbers[0] = numbers[0] ^ numbers[1]
    return numbers
};
```
