### 解题思路
保存最小值

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $price = PHP_INT_MAX;
        $res = 0;
        for($i=0;$i<count($prices);$i++){
            if($prices[$i]<$price){
                $price = $prices[$i];
            }else{
                $res = max($res,$prices[$i]-$price);
            }
        }
        return $res;
    }
}
```