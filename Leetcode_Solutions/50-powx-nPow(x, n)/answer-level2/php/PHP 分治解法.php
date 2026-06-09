### 解题思路


### 代码

```php
class Solution {

    /**
     * @param Float $x
     * @param Integer $n
     * @return Float
     */
    function myPow($x, $n)
    {
        if ($x == 0) return 0;
        if ($n < 0) {
            $x = 1 / $x;
            $n = -$n;
        }

        return $this->helper($x, $n);
    }

    function helper($x, $n)
    {
        // terminator
        if ($n == 0) {
            return 1;
        } elseif ($n == 1) {
            return $x;
        }

        // process and drill down
        $subResult = $this->helper($x, $n / 2);
        // merge
        if ($n % 2 == 1) {
            return $subResult * $subResult * $x;
        } else {
            return $subResult * $subResult;
        }

        // revert
    }
}
```