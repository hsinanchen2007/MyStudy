时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String[] $ops
     * @return Integer
     */
    function calPoints($ops) {
        $array = [];
        $i = 0;

        foreach ($ops as $value) {
            switch ($value) {
                case 'C':
                    unset($array[$i - 1]);
                    $i--;
                    break;
                case 'D':
                    $array[$i] = $array[$i - 1] * 2;
                    $i++;
                    break;
                case '+':
                    $array[$i] = $array[$i - 2] + $array[$i - 1];
                    $i++;
                    break;
                default:
                    $array[$i] = $value;
                    $i++;
                    break;
            }
        }

        $points = 0;

        for ($i = 0, $count = count($array); $i < $count; $i++) {
            $points += $array[$i];
        }

        return $points;
    }
}
```