### 解题思路
根据首页官方解题思路，关键点在 $minPrice = min($minPrice,$value); 通过不断筛选最小的价格，来做到动态规划的处理。
官方的思路很好懂~

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $maxProfit = 0;
        $minPrice = $prices[0];
        foreach($prices as $key=>$value){
            $minPrice = min($minPrice,$value);
            if($value - $minPrice > $maxProfit){
                $maxProfit = $value - $minPrice;
            }
        }
        return $maxProfit;
    }
}
```