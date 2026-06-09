如果m != n,那么m+1与m最低位一定不同，
也就是最低位相与一定为0，所以可以把m和n的最低位置为0，
如果m和n还不相等，那么m和m + 2相与第二低位也为0，同样可以把m和n
第二低位置为0，以此类推，直到m == n为止


```
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var rangeBitwiseAnd = function(m, n) {
    let count = 0
    while(m !== n) {
       m >>= 1
       n >>= 1
       count++
    }
    return m << count
};
```
