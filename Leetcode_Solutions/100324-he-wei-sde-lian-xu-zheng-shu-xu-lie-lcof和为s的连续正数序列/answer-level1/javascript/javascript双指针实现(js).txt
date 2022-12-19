javascript双指针实现

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    const arr = [];
    let i = 1;
    let j = 2;
    while (i < j) {
        const totle = ((i + j) * (j - i + 1)) * 0.5;
        if (totle > target) {
            i++;
        } else if (totle < target) {
            j++;
        } else {
            const temp = [];
            for (let k = i; k <= j; k++) {
                temp.push(k);
            }
            arr.push(temp);
            i++;
            j++;
        }
    }
    return arr;
};
```