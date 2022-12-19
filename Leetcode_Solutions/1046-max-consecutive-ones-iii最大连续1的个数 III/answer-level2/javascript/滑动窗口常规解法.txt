```
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var longestOnes = function(A, K) {
    let i = 0
    let j = -1
    const n = A.length
    let count = 0
    while(++j < n) {
        if(A[j] === 1) count++
        if(count + K < j - i + 1) {
            if(A[i++] === 1) {
                if(count > 0) {
                    count--
                } else count = 0
            }
        }
        
    }
    return n - i
};
```
