```
    // Time: O(log_5(n)), Space: O(1)
    function trailingZeroes($n) {
        $cnt = 0;
        //$n > 0 or $n >= 5
        while ($n > 0) {
            $n = floor($n/5);
            $cnt += $n;
        }
        return $cnt;
    }
```
