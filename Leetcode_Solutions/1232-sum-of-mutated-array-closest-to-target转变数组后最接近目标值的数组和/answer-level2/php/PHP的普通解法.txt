```php
<?php

function findBestValue($arr, $target){
    # 1.
    if (array_sum($arr) <= $target){
        return max($arr);
    }

    # 2.
    $avg = round($target / count($arr));
    if (avg <= min($arr)){
        return $avg;
    }

    # 3.
    $surplus = $target - min($arr);
    $surplus_count = count($arr)-1;
    return ($surplus % $surplus_count > $surplus_count / 2) ? ceil($surplus / $surplus_count) : floor($surplus / $surplus_count);
}

# 第一种情况
$arr = [2,3,5];
$target = 10;
var_dump(findBestValue($arr,$target));

# 第二种情况
$arr = [4,9,3];
$target = 10;
var_dump(findBestValue($arr,$target));

# 以下两个例子满足第三种情况
# floor
$arr = [1547,83230,57084,93444,70879];
$target = 71237;
var_dump(findBestValue($arr,$target)); // 17422

# ceil
$arr = [40091,2502,74024,53101,60555,33732,23467,40560,32693,13013];
$target = 78666;
var_dump(findBestValue($arr,$target)); // 8463
?>
```
