```
function minMoves2($nums)
{
    sort($nums);
    $median = $nums[intval(count($nums) / 2)];
    $frequency = 0;
    foreach($nums as $key => $val) {
        $frequency += abs($val - $median);
    }
    return $frequency;
}
```