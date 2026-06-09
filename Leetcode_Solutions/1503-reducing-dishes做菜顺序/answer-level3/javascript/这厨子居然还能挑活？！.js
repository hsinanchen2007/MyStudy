### 解题思路
![image.png](https://pic.leetcode-cn.com/1236ea1498311c7c19a006dde758530f9afc7d51b25ae0ad5f5cfc91a37a66f3-image.png)

先考虑全负数数和全非负数的情况，然后每次加一个负数，看总数变大还是变小。

### 代码

```javascript
/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function(satisfaction) {
    if (satisfaction.findIndex(val => {
        return val >= 0;
    }) == -1) {
        return 0;
    }
    let sum = 0;
    if (satisfaction.findIndex(val => {
        return val < 0
    }) == -1) {
        satisfaction.sort((a, b) => a - b);
        satisfaction.forEach((val, idx) => {
            sum += val * (idx + 1);
        })
        return sum;
    }

    let pstvSum = 0,
        roundSum = 0,
        pos = [],
        neg = [];

    satisfaction.forEach((val, idx) => {
        if (val >= 0) {
            roundSum += val;
            pos.push(val);
        } else if (val < 0) {
            neg.push(val);
        }
    })
    pos.sort((a, b) => a - b);
    pos.forEach((val, idx) => {
        pstvSum += val * (idx + 1);
    })
    sum = pstvSum;
    neg.sort((a, b) => b - a);
    let negRoundSum = 0,
        negSum = 0;

    for (let i = 0; i < neg.length; i++) {
        negRoundSum = 0;
        for (let j = 0; j <= i; j++) {
            negRoundSum += neg[j];
        }
        negSum += negRoundSum;
        sum = Math.max(sum, pstvSum + (i + 1) * roundSum + negSum);
    }

    return sum;
};
```