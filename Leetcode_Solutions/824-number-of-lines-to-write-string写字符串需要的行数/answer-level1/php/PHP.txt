时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $widths
     * @param String $S
     * @return Integer[]
     */
    function numberOfLines($widths, $S) {
        $hash = [
            'a' => 0,
            'b' => 1,
            'c' => 2,
            'd' => 3,
            'e' => 4,
            'f' => 5,
            'g' => 6,
            'h' => 7,
            'i' => 8,
            'j' => 9,
            'k' => 10,
            'l' => 11,
            'm' => 12,
            'n' => 13,
            'o' => 14,
            'p' => 15,
            'q' => 16,
            'r' => 17,
            's' => 18,
            't' => 19,
            'u' => 20,
            'v' => 21,
            'w' => 22,
            'x' => 23,
            'y' => 24,
            'z' => 25
        ];

        $row = 1;
        $width = 0;

        for ($i = 0, $length = strlen($S); $i < $length; $i++) {
            if ($width + $widths[$hash[$S[$i]]] > 100) {
                $row++;
                $width = $widths[$hash[$S[$i]]];
            } else {
                $width += $widths[$hash[$S[$i]]];
            }
        }

        return [$row, $width];
    }
}
```