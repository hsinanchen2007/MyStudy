### 解题思路
迭代过程中就要进行取模运算，否则可能会溢出。

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function fib($n) {
        if ($n <= 1) return $n;

        $pre = 0;
        $cur = $res = 1;
        for ($i = 2; $i <= $n; ++$i) {
            $res = ($pre + $cur) % 1000000007;
            $pre = $cur;
            $cur = $res;
        }

        return $res;
    }
}
```