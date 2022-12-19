### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function (num) {
    let time = 0;
    while (num !== 0) {
        num = num % 2 === 0 ? num / 2 : num - 1;
        time++;
    }
    return time;
};
```