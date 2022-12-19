### 解题思路
只要之后一天跌就停，否则就网上加差价

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $profit = 0;
        for($i=0;$i<sizeof($prices)-1;$i++){
            $diff = $prices[$i+1]-$prices[$i];
            if($diff>0) $profit += $diff;
        }
        // echo $profit;
        return $profit;
    }
}
```