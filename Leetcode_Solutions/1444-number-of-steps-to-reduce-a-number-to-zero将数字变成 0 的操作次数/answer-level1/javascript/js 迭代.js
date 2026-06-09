```
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function (num) {
    let ret = 0
    while (num) {
        num = num % 2 ? --num : num / 2
        ret++
    }
    return ret
};
```
