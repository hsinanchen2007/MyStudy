### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
      var canThreePartsEqualSum = function(A) {
            const len = A.length
            const sum = A.reduce((a, b) => a + b)
            if (sum % 3) {
                return false
            }
            const per = sum / 3
            let i = 1
            let j = len - 2
            let sum1 = A[0]
            let sum2 = A[len - 1]
            while (sum1 !== per && i < len) {
                sum1 += A[i]
                i ++
            }
            while (sum2 !== per && j >= 0) {
                sum2 += A[j]
                j --
            }
            i --
            j ++
            if (sum1 === per && sum2 === per && i + 1 < j) {
                return true
            } else {
                return false
            }
        };
```