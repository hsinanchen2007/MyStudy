### 解题思路
计算最低值，与之后每一点与最低值的差

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        //只需记录与实时更新最低点，和之后每一点与最低点的差即可
        $max = 0;
        $min = $prices[0];

        for($i=1;$i< count($prices); $i++)
        {
            if($prices[$i]  < $min)
            {
                $min = $prices[$i];//如果当前点小于最低点，则更新 最低点
            }
            if($prices[$i] - $min > $max)
            {
                $max =   $prices[$i] - $min ;//如果当前点大于最低点，则计算差值，并更新最大利润值
            }    
        }

        return $max;
    }
}
```