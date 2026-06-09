```php
 /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $status[0][0]=$status[0][2]=0;
        $status[0][1]=-$prices[0];
        $res=0;
        for($i=1;$i<count($prices);$i++){
            $status[$i][0]=$status[$i-1][0];
            $status[$i][1]=max($status[$i-1][1],$status[$i-1][0]-$prices[$i]);
            $status[$i][2]=$status[$i-1][1]+$prices[$i];
            $res = max($res,$status[$i][0],$stauts[$i][1],$status[$i][2]);
        }
        return $res;
    }

```