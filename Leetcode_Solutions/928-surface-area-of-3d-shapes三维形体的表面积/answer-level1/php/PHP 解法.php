```php
class Solution
{

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function surfaceArea($grid)
    {
        $row = count($grid);
        if ($row == 0) return 0;
        $col = count($grid[0]);
        $count = 0;
        for ($i = 0; $i < $row; ++$i) {
            for ($j = 0; $j < $col; ++$j) {
                if ($grid[$i][$j] == 0) continue;
                $count += 2;
                $count += max($grid[$i][$j] - $grid[$i - 1][$j] ?? 0, 0);
                $count += max($grid[$i][$j] - $grid[$i + 1][$j] ?? 0, 0);
                $count += max($grid[$i][$j] - $grid[$i][$j - 1] ?? 0, 0);
                $count += max($grid[$i][$j] - $grid[$i][$j + 1] ?? 0, 0);
            }
        }

        return $count;
    }
}
```
