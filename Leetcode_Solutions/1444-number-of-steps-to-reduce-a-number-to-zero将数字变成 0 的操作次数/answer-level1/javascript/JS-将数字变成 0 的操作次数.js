### 解题思路
递归

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function (num) {
    var count = 0;
    var recursionFn = function (num) {
        count++;
        if (num % 2 === 0) {
            num = num / 2;
        }
        else {
            num = num - 1;
        }
        if (num === 0) {
            return
        }
        recursionFn(num);
    }
    recursionFn(num);
    return count;
};
```