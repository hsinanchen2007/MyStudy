```
/**
 * @param {number[]} arr
 * @return {number}
 */
var maxNumberOfApples = function (arr) {
    arr = arr.sort((a, b) => (a - b));
    let sum = 0;
    let result = 0

    arr.map((item, index) => {
        sum += item;
        if (sum > 5000  && !result) {
            result = index
        }
    })
    return result || arr.length
};
```
