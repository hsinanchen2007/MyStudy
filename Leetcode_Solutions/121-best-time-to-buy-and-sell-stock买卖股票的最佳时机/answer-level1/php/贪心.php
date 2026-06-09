### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    /*function maxProfit($prices) {
        if(empty($prices)){
            return 0;
        }
        $count=count($prices);
        //贪心
        $max=0;
        $minPrice=$prices[0];
        for($i=1;$i<$count;$i++){
            if($prices[$i]<$minPrice){
                $minPrice=$prices[$i];
            }
            if($prices[$i]-$minPrice>$max){
                 $max=$prices[$i]-$minPrice;
            }

        }
        return $max;
    }*/
    function maxProfit2($prices) {
        if(empty($prices)){
            return 0;
        }
        $count=count($prices);
        //贪心
        $max=0;
        for($i=0;$i<$count;$i++){
            for($j=$i+1;$j<$count;$j++){
                if($prices[$j]-$prices[$i]>$max){
                    $max=$prices[$j]-$prices[$i];
                }
            }
            

        }
        return $max;
    }
}
```