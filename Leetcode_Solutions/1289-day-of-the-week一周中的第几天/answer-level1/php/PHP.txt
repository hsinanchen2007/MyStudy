时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $day
     * @param Integer $month
     * @param Integer $year
     * @return String
     */
    function dayOfTheWeek($day, $month, $year) {
        $date = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'];

        if ($month == 1 || $month == 2) {
            $month += 12;
            $year--;
        }

        $num = ($day + 2 * $month + ((int) (3 * ($month + 1) / 5)) + $year + ((int) ($year / 4)) - ((int) ($year / 100)) + ((int) ($year / 400))) % 7; // 基姆拉尔森计算公式

        return $date[$num];
    }
}
```