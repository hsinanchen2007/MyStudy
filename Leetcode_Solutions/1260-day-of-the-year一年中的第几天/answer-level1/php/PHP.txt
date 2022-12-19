时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $date
     * @return Integer
     */
    function dayOfYear($date) {
        $year = (int) ($date[0] . $date[1] . $date[2] . $date[3]);
        $month = (int) ($date[5] . $date[6]);
        $day = (int) ($date[8] . $date[9]);

        $num = 0;
        $array = [
            1  => 31,
            2  => ($year % 4 == 0 && ($year % 100 != 0 || $year % 400 == 0)) ? 29 : 28,
            3  => 31,
            4  => 30,
            5  => 31,
            6  => 30,
            7  => 31,
            8  => 31,
            9  => 30,
            10 => 31,
            11 => 30,
            12 => 31
        ];

        for ($i = 1; $i < $month; $i++) {
            $num += $array[$i];
        }

        return $num += $day;
    }
}
```