```
class Solution {

    /**
     * @param Integer $n
     * @desc  按位& 2的幂次方 二进制只有1 
     * @return Boolean
     */
    function isPowerOfTwo($n) {
        return $n > 0 && ($n & ($n -1)) == 0;
    }
}
```