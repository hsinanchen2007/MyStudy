# 版本1.0，问题点，内存使用过高
```
    function maxSubArray($nums) {
        $max = $nums[0];
        $sum = $nums[0];
        foreach ($nums as $key=>$val) {
            // 如果该数组只有一个值，则该值即最大值
            // 如果该数组有多个值，需注意第一个值
            if ($key == 0) {
                continue;
            }
            if ($sum > 0) {
                $sum += $val;
            } else {
                $sum = $val;
            }
            $max = max($max, $sum);
        }
        return $max;
    }

```
