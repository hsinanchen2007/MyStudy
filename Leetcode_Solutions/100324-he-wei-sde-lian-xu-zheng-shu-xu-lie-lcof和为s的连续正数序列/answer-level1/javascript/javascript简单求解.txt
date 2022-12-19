最后一项肯定是小于target值，用target作为循环的终止条件。这样缺点可能是多循环了次数，但也能解决问题。
```
var findContinuousSequence = function(target) {
    let result = [];
    let temp = [];
    let sum = 0;
    for (let i = 1; i <= target; i++) {
        temp.push(i)
        sum = temp.reduce((pre, cur) => pre + cur)
        while (sum > target) {
            sum -= temp[0]
            temp.shift()
        }
        if (sum === target) {
            temp.length >= 2 && result.push([...temp])
        }
    }
    return result
};
```
