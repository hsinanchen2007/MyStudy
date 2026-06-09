### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @param Integer $fee
     * @return Integer
     */
    function maxProfit($prices, $fee) {
        $count = count($prices);

        $dp_i_0 = 0; $dp_i_1 = PHP_INT_MIN;

        for($i = 0; $i < $count; $i++){
            $temp = $dp_i_0;
            $dp_i_0 = max($dp_i_0, $dp_i_1 + $prices[$i]);
            $dp_i_1 = max($dp_i_1, $dp_i_0 - $prices[$i] - $fee);
        }

        return $dp_i_0;

    }
}
```