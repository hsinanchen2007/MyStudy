
```
function generateParenthesis($n)
    {
        if ($n == 0) {
            return [];
        }
        if ($n == 1) {
            return ["()"];
        }
        $dp = [];
        $dp[0][] = "";
        $dp[1][] = "()";
        for ($i = 2; $i < $n + 1; $i++) {
            for ($j = 0; $j < $i; $j++) {
                for ($p = 0; $p < count($dp[$j]); $p++) {
                    for ($q = 0; $q < count($dp[$i - $j - 1]); $q++) {
                        $dp[$i][] = "(" . $dp[$j][$p] . ")" . $dp[$i - $j - 1][$q];
                    }
                }
            }
        }
        return $dp[$n];
    }


```
