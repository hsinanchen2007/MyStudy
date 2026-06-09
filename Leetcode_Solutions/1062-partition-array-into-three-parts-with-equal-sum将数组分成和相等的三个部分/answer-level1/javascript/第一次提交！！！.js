```
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function (A) {
    let sum = A.reduce((a, b) => a + b), temp = sqe = sum / 3, count = 0
    for (let a of A) {
        sqe = sqe - a
        if (sqe === 0) {
            count++
            sqe = temp
        }
    }
    return count >= 3 || false
};
```
