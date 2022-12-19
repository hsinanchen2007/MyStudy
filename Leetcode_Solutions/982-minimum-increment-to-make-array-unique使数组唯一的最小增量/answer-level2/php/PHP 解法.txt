先打卡，慢慢消化

```php
class Solution
{

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function minIncrementForUnique($A)
    {
        // 先排序再比较
        $a = self::quickSort($A);
        $count = count($a);
        $last = $a[0];

        $sum = 0;
        for ($i = 1; $i < $count; $i++) {
            if ($a[$i] <= $last) {
                $sum += $last + 1 - $a[$i];
                $last += 1;
            } else {
                $last = $a[$i];
            }
        }

        return $sum;
    }

    function quickSort($A)
    {
        $count = count($A);
        if ($count < 2) {
            return $A;
        }
        $mid = $A[0];
        $left = [];
        $right = [];
        foreach ($A as $k => $value) {
            if ($k == 0) {
                continue;
            }
            if ($value > $mid) {
                $right[] = $value;
            } else {
                $left[] = $value;
            }
        }

        return array_merge(self::quickSort($left), [$mid], self::quickSort($right));
    }
}
```
