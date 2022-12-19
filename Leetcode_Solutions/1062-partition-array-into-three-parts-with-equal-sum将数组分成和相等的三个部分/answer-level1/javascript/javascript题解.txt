要注意细节处理。

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    if (A.length === 0) return true;
    let sum = A.reduce((pre, cur) => pre + cur);
    if ((sum / 3) !== Math.floor(sum / 3)) return false;
    let left = 0, leftSum = A[0], part = sum/3;
    let right = A.length - 1, rightSum = A[A.length-1];
    while (left + 1 < right) {
        if (leftSum === part && rightSum === part) return true;
        if (leftSum !== part) {
            leftSum += A[++left];
        }
        if (rightSum !== part) {
            rightSum += A[--right];
        }
    }
    return false;
};
```