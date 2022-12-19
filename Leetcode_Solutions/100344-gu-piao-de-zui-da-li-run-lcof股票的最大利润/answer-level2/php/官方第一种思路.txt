### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $buyPrice = PHP_INT_MAX;//买入的价格
        $profit = 0;//利润
        foreach($prices as $k=>$v){
            //尽量寻找低的买入价格
            $buyPrice = min($buyPrice,$v);
            //尽量得到高的利润
            $profit = max($profit,$v - $buyPrice);
        }
        
        return $profit;
    }
}
```