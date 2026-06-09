```php
function sumFourDivisors($nums) {
    $res = 0;
    for ($i = 0; $i < count($nums); $i++){
        $sum = 0;
        for ($j = 2; $j <= $nums[$i]/$j; $j++){
            if ($nums[$i] % $j == 0){
                if ($sum == 0 && $nums[$i]/$j != $j) {
                    $sum = 1 + $nums[$i] + $j + $nums[$i] / $j;
                }else{
                    $sum = 0;
                    break;
                }
            }
        }
        $res += $sum;
    }
    return $res;
}
```

刚开始写的没有通过是因为没有考虑到类似于16，81这种例子...
加了$nums[$i]/$j != $j的判断条件就可以了。
