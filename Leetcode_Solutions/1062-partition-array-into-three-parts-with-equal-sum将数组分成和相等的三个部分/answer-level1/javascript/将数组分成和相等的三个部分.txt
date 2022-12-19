```js
var canThreePartsEqualSum = function(A) {
    let sum = 0
    for (let val of A) {
        sum += val
    }
    if (sum % 3 !== 0) {
        return false
    }
    let one_third = sum / 3;
    let sum1 = 0
    let sum3 = 0
    for (i = 0; i < A.length; i++) {
        if (sum1 !== one_third) {
            sum1 += A[i]
        } else {
            break
        }
    }
    for (j = A.length - 1; j >= 0; j--) {
        if (sum3 !== one_third) {
            sum3 += A[j]
        } else {
            break
        }
    }
    return i <= j
};
```
