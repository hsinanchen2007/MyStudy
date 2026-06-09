### 解题思路
使用循环乘积和求和，同时可以使用数组array_product和array_sum直接计算。

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function subtractProductAndSum($n) {
        $arr = str_split($n);
        $sum = 0;
        $multi = 1;

        foreach($arr as $value) {
            $sum += $value;
            $multi *= $value;
        }

        return $multi - $sum;
    }
}
```