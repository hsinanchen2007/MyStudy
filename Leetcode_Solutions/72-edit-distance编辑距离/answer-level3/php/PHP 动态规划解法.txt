```php
function minDistance($word1, $word2)
{
    // 自底向上的 dp
    $l1 = strlen($word1);
    $l2 = strlen($word2);
    $dp = array_fill(0, $l1 + 1, array_fill(0, $l2 + 1, 0));
    // base case
    for ($i = 1; $i <= $l1; ++$i) {
        $dp[$i][0] = $i;
    }
    for ($j = 1; $j <= $l2; ++$j) {
        $dp[0][$j] = $j;
    }

    for ($i = 1; $i <= $l1; ++$i) {
        for ($j = 1; $j <= $l2; ++$j) {
            // 注意下标
            if ($word1[$i - 1] == $word2[$j - 1]) {
                $dp[$i][$j] = $dp[$i - 1][$j - 1];
            } else {
                $dp[$i][$j] = min(
                    // delete
                    $dp[$i - 1][$j],
                    // insert
                    $dp[$i][$j - 1],
                    // replace
                    $dp[$i - 1][$j - 1]
                ) + 1;
            }
        }
    }

    return $dp[$l1][$l2];
}
```
