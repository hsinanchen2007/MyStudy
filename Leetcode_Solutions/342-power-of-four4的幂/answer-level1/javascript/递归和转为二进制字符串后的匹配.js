JavaScript写的递归：
```
/**
 * @param {number} num
 * @return {boolean}
 */
var isPowerOfFour = function(num) {
    return (typeof num!=='number') || num==0 || (num%1!==0) ? false : (num==4 || num==1 ? true : isPowerOfFour(num/4));
};
```


Python3写的2*N次方或者4*N次方的思路：
```
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        return bin(num)[2:].replace('00', '') == '1'
```
