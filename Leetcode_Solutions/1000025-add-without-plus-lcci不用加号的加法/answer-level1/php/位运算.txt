位运算 phpphp版本

```
/**
     * @param Integer $a
     * @param Integer $b
     * @return Integer
     */
    function add($a, $b) {
        while ($b != 0) {
            $sum = $a ^ $b;
            $carry = ($a & $b) << 1;
            $a = $sum;
            $b = $carry;
        }
        return $a;
    }
```
