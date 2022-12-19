### 解题思路

见代码注释

### 代码

```php
class Solution {

    /**
     * @param Integer $a
     * @param Integer $b
     * @return Integer
     */
    function getSum($a, $b) {
        // a + b 的问题拆分为 (a 和 b 的无进位结果) + (a 和 b 的进位结果)
        // 无进位加法使用异或运算计算得出
        // 进位结果使用与运算和移位运算计算得出
        // 循环此过程，直到进位为 0

        // terminator
        if ($a == 0) return $b;
        if ($b == 0) return $a;

        // process current level
        $c = $a ^ $b;
        $d = ($a & $b) << 1;

        // drill down
        return $this->getSum($c, $d);
    }
}
```