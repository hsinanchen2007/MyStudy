```
function maxProfit($prices) {
    if(empty($prices)) return 0;
    $sell[0] = 0;
    $cool[0] = 0;
    $buy[0] = -$prices[0];
    for($i=1;$i<count($prices);$i++){
        $sell[$i] = max($sell[$i-1],$buy[$i-1]+$prices[$i]);
        $buy[$i] = max($buy[$i-1],$cool[$i-1]-$prices[$i]);
        $cool[$i] = max($cool[$i-1],$sell[$i-1]);
    }
    return max($sell[count($prices)-1],$buy[count($prices)-1],$cool[count($prices)-1]);
}
```
