```
function generate($numRows)
{
    $return = [];
    for ($i = 0; $i < $numRows; $i++) {
        for ($j = 0; $j <= $i; $j++) {
            if (!isset($return[$i - 1][$j - 1]) || !isset($return[$i - 1][$j])) {
                $return[$i][$j] = 1;
            } else {
                $return[$i][$j] = $return[$i - 1][$j - 1] + $return[$i - 1][$j];
            }
        }
    }
    return $return;
}
```