### 解题思路
官方解之二

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @param Integer $y
     * @param Integer $z
     * @return Boolean
     */
    function canMeasureWater($x, $y, $z)
    {
        // 贝祖定理
        if ($x + $y < $z) return false;
        if ($x == 0 || $y == 0) return $z == 0 || $x + $y == $z;
        return $z % $this->gcd($x, $y) == 0;
    }

    private function gcd($a, $b)
    {
        if ($a == 0 || $b == 0) return max(abs($a), abs($b));

        $r = $a % $b;
        return $r != 0 ? $this->gcd($b, $r) : abs($b);
    }
}
```