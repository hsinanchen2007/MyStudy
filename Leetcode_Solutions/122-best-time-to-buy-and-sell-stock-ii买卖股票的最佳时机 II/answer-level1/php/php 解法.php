```
function maxProfit($prices) {
    $maxprofit = 0;
    for($i = 1;$i < count($prices); $i++)
        if($prices[$i] > $prices[$i-1])
            $maxprofit += $prices[$i] - $prices[$i-1];
    return $maxprofit;
}
```
