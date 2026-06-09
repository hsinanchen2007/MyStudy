### 解题思路
最后一种很厉害

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        // $max = 0;
        // $n_len = count($prices);
        // $left = 0;
        // $right = $n_len;
        // while($left < $n_len){

        //     if($left == $right) {
        //         $left++;
        //         $right = $n_len;
        //     }
        //     else{
        //         $max = max($max, $prices[$right] - $prices[$left]);
        //         $right--;
        //     } 
        // }
        // return $max;

        // $minVal = $prices[0];
        // $maxProfit = 0;
        // for($i=1; $i<count($prices); $i++){
        //     echo $prices[$i] . " > " . $minVal . " >> ";
        //     if($prices[$i] < $minVal){
        //         echo "111 >> ";
        //         $minVal = $prices[$i];
        //     } elseif(($prices[$i] - $minVal) > $maxProfit){
        //         echo "222 >> ";
        //         $maxProfit = $prices[$i] - $minVal;
        //     }
        //     echo $minVal . "\n";
        // }

        //只需记录与实时更新最低点，和之后每一点与最低点的差即可
        $max_profit = 0;
        $min_buyin = $prices[0];

        for($i=1;$i<count($prices);$i++)
        {
            $min_buyin = min($min_buyin, $prices[$i]);
            $max_profit = max($max_profit, $prices[$i] - $min_buyin);
        }

        return $max_profit;


    }
}
```