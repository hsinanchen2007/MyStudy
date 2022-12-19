### 解题思路
n = n & (n-1) 的作用是减掉后面的一位1 记着这个就比较好记了。

### 代码

```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function hammingWeight($n) {
        $count = 0 ;
        while($n){
            $n &= $n - 1;
            $count ++;
        }
        return $count;
    }
}
```