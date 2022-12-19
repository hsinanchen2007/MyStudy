非位运算的解法。
这里使用的是数组键名做判重比较。键名比键值效率高
这种解法没位运算快。
```
function maxProduct($words) {
    $n = count($words);
    $max = 0;
    $arr = [];
    for($i = 0; $i < $n; $i++) {
        for($j = 0; $j < strlen($words[$i]); $j++) {
            $arr[$i][$words[$i][$j]] = 1;
        }
    }
    for($i = 0; $i < $n-1; $i++) {
        for($j = $i+1; $j < $n; $j++) {
            if(empty(array_intersect_key($arr[$i],$arr[$j]))){
                $max = max($max,strlen($words[$i])*strlen($words[$j]));
            }
        }
    }
    return $max;
}
```
