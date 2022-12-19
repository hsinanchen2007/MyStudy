```

    function maxArea($height) {
         $max = 0;
        $left = 0;
        $right = count($height) - 1;
        while ($left != $right) {
            if ($height[$left] < $height[$right]) {
                $area = $height[$left] * ($right - $left);
                $left += 1;
            } else {
                $area = $height[$right] * ($right - $left);
                $right -= 1;
            }
            $max = max($max, $area);
        }
        return $max;
    }
```