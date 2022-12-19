### 解题思路
官方题解思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    let sum = A.reduce((x, y) => x + y, 0);
    if (sum % 3 != 0) return false;
    let kSum = 0;
    let k = 0;
    let i = -1;
    let j = -1;
    while (k < A.length) {
        kSum += A[k];
        //[10,-10,10,-10,10,-10,10,-10]
        if (i < 0 && kSum == sum / 3) i = k;
        //[12,-4,16,-5,9,-3,3,8,0]
        if (k > i && i >= 0 && kSum == 2 * sum / 3) {
            j = k;
            break;
        };
        k++;
    }
    // [-1, 1, -1, 1]
    if (i < 0 || j < 0 || j >= A.length - 1) return false;
    return true;
};
```