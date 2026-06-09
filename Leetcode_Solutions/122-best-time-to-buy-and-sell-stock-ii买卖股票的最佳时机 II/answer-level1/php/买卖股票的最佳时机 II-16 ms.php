### 解题思路
没管那么多，只要第二天涨价就进行一次买卖

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $num = 0;
        $i = 0;
        while ($i < count($prices)-1) {
            if ($prices[$i]<$prices[$i+1]) {
                $num += $prices[$i+1]-$prices[$i];
            }
            else {
                $num += 0; 
            }
            $i++;
        }
        return $num;
    }
}
```