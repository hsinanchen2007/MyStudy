例题三写得太有欺骗性了，提交发现错误了之后再试了一下其他例子才搞懂它不是分组，而且窗口滑动的模式，实现的思路应该是相似的
```
$count = 0;
        $length = count($calories);
        $sum = 0;
        for ($i = 0; $i < $length; $i ++ ){
            $sum += $calories[$i];
            if ($i >= $k) {
                $sum -=$calories[$i - $k];
            }
            if ($i >= $k - 1) {
                if ($sum > $upper) {
                    $count ++;
                } elseif ($sum < $lower) {
                    $count --;
                }
            }
        }
        return $count;
```
