```
 function minDistance($word1, $word2) {
          $m = strlen($word1);
        $n = strlen($word2);
        $dp = [];
        for ($i = 0; $i < $m + 1; $i++) {
            $dp[$i][0] = $i;
        }
        for ($j = 0; $j < $n + 1; $j++) {
            $dp[0][$j] = $j;
        }
        for ($k = 1; $k < $m + 1; $k++) {
            for ($l = 1; $l < $n + 1; $l++) {
                $dp[$k][$l] = min($dp[$k - 1][$l - 1] + ($word1[$k - 1] == $word2[$l - 1] ? 0 : 1),
                    $dp[$k - 1][$l] + 1, $dp[$k][$l - 1] + 1);
            }
        }
        return $dp[$m][$n];
    }
```