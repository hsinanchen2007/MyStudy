### 解题思路
看了大佬的二进制运算觉得自己的方法好丢人

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function (num) {
    let index = 0
    while (num !== 0) {
        parseInt(num / 2) === num / 2 ? num = num / 2 : num -= 1
        index++
    }
    return index
};
```