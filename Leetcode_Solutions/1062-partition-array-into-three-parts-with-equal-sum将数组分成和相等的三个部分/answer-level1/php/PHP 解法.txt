求和，分三段计算，要注意每一段都不能为空

```php
class Solution
{

    /**
     * @param Integer[] $A
     * @return Boolean
     */
    function canThreePartsEqualSum($A)
    {
        $n = count($A);
        if ($n <= 3) return false;
        $sum = array_sum($A);
        if ($sum % 3 != 0) return false;
        $part1 = 0;
        for ($i = 0; $i < $n; ++$i) {
            $part1 += $A[$i];
            if ($part1 == $sum / 3) break;
        }
        // tricky
        if ($i >= $n - 1) return false;

        $part2 = 0;
        for ($j = $i + 1; $j < $n; ++$j) {
            $part2 += $A[$j];
            if ($part2 == $sum / 3) break;
        }

        // tricky
        if ($j >= $n - 1) return false;
        return true;
    }
}
```
