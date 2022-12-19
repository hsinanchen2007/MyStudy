
解法一：

```php
function twoSumOne()
{
    $subscriptArr = [];
    $len = count($this->arr);

    for ($i = 0; $i < $len - 1; $i++) {
        for ($j = $i + 1; $j < $len; $j++) {

            if ($this->arr[$i] + $this->arr[$j] == $this->target) {
                $subscriptArr = [$i, $j];
            }
        }
    }

    return $subscriptArr;
}
```


解法二：执行用时 : 16 ms , 在所有 PHP 提交中击败了 92.46% 的用户
```php
function twoSumTwo($nums, $target)
{
    if (!is_array($nums) || count($nums) < 2) {
        return [];
    }

    $sortArr = $nums;
    asort($sortArr);
    $sortArr = array_values($sortArr);

    $len = count($nums);
    $left = 0;
    $right = $len - 1;
    $firNum = $secNum = null;

    while ($left < $right) {
        if ($sortArr[$left] + $sortArr[$right] == $target) {
            $firNum = $sortArr[$left];
            $secNum = $sortArr[$right];
            break;
        }
        $sortArr[$left] + $sortArr[$right] > $target ? $right-- : $left++;
    }
    if (is_null($firNum) || is_null($secNum)) {
        return [];
    }
    $fir = array_search($firNum, $nums);
    unset($nums[$fir]);
    $sec = array_search($secNum, $nums);

    return [$fir, $sec];
}
```

